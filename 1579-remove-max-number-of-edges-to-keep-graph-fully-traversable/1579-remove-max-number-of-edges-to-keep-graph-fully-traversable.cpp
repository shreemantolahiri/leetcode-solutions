class Solution {
    class DSU {
    public:
        vector<int> size, parent;

        // Constructor to initialize DSU
        DSU(int n) {
            size.resize(n + 1, 1); // Initialize size array
            parent.resize(n + 1);  // Initialize parent array

            // Everyone is its own parent initially
            for (int i = 0; i <= n; i++) {
                parent[i] = i;
            }
        }

        // Find the ultimate parent of a node with path compression
        int findUltPar(int node) {
            if (node == parent[node]) return node;
            return parent[node] = findUltPar(parent[node]);
        }

        // Union two nodes by size
        void unionBySize(int u, int v) {
            int uPar = findUltPar(u);
            int vPar = findUltPar(v);

            if (uPar == vPar) return; // If they already have the same parent, do nothing

            // Perform union by size
            if (size[uPar] < size[vPar]) {
                parent[uPar] = vPar;
                size[vPar] += size[uPar];
            } else {
                parent[vPar] = uPar;
                size[uPar] += size[vPar];
            }
        }
    };

public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        DSU a(n), b(n); // DSU for Alice and Bob

        int count = 0; // To count the number of removable edges
        int totalEdgesAdded = 0; // To count total edges added for each DSU

        // Step 1: Process type 3 edges first (shared by both Alice and Bob)
        for (const auto& edge : edges) {
            if (edge[0] == 3) {
                int u = edge[1];
                int v = edge[2];
                if (a.findUltPar(u) != a.findUltPar(v) || b.findUltPar(u) != b.findUltPar(v)) {
                    a.unionBySize(u, v);
                    b.unionBySize(u, v);
                    totalEdgesAdded++;
                } else {
                    count++;
                }
            }
        }

        // Step 2: Process type 1 edges (only for Alice)
        for (const auto& edge : edges) {
            if (edge[0] == 1) {
                int u = edge[1];
                int v = edge[2];
                if (a.findUltPar(u) != a.findUltPar(v)) {
                    a.unionBySize(u, v);
                    totalEdgesAdded++;
                } else {
                    count++;
                }
            }
        }

        // Step 3: Process type 2 edges (only for Bob)
        for (const auto& edge : edges) {
            if (edge[0] == 2) {
                int u = edge[1];
                int v = edge[2];
                if (b.findUltPar(u) != b.findUltPar(v)) {
                    b.unionBySize(u, v);
                    totalEdgesAdded++;
                } else {
                    count++;
                }
            }
        }

        // Step 4: Check if both graphs are fully traversable
        int aComponents = 0, bComponents = 0;
        for (int i = 1; i <= n; i++) {
            if (a.parent[i] == i) aComponents++;
            if (b.parent[i] == i) bComponents++;
        }

        if (aComponents > 1 || bComponents > 1) return -1;
        return count;
    }
};
