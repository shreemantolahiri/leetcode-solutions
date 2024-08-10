class Solution {
public:
    // Disjoint Set Union (DSU) or Union-Find data structure
    class DSU {
    public:
        int n;
        vector<int> par, siz;

        // Constructor initializes n elements with their respective parents
        DSU(int m) : n(m), par(m), siz(m, 1) {
            for (int i = 0; i < n; i++) {
                par[i] = i;
            }
        }

        // Find the ultimate parent (with path compression)
        int findUPar(int u) {
            if (par[u] == u) return u;
            return par[u] = findUPar(par[u]);
        }

        // Union by size - attach smaller tree under larger one
        void unionBySize(int u, int v) {
            int ulpU = findUPar(u);
            int ulpV = findUPar(v);

            if (ulpU == ulpV) return; // Already in the same component

            if (siz[ulpV] > siz[ulpU]) {
                siz[ulpV] += siz[ulpU];
                par[ulpU] = ulpV;
            } else {
                siz[ulpU] += siz[ulpV];
                par[ulpV] = ulpU;
            }
        }
    };

    int regionsBySlashes(vector<string>& grid) {
        int n = grid.size();
        int m = n * n * 4;  // Each cell is divided into 4 parts
        DSU dsu(m);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int num = i * n + j;
                int first = 4 * num;
                int second = first + 1;
                int third = first + 2;
                int fourth = first + 3;

                char ch = grid[i][j];

                // Union the parts within the current cell
                if (ch == ' ') {
                    dsu.unionBySize(first, second);
                    dsu.unionBySize(second, third);
                    dsu.unionBySize(third, fourth);

                } else if (ch == '/') {
                    dsu.unionBySize(first, second);
                    dsu.unionBySize(third, fourth);
                } else {  // ch == '\\'
                    dsu.unionBySize(first, third);
                    dsu.unionBySize(second, fourth);
                }

                // Union with the left neighbor
                if (j > 0) {
                    int leftFourth = 4 * (num - 1) + 3;
                    dsu.unionBySize(first, leftFourth);
                }

                // Union with the upper neighbor
                if (i > 0) {
                    int upperThird = 4 * (num - n) + 2;
                    dsu.unionBySize(second, upperThird);
                }
            }
        }

        // Count unique components (roots) in the DSU
        int count = 0;
        for (int i = 0; i < m; i++) {
            if (dsu.findUPar(i) == i) count++;
        }

        return count;
    }
};
