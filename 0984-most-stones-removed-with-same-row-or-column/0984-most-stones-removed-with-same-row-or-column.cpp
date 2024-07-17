class Solution {
    class DSU {
    public:
        vector<int> size, parent;
        // Constructor to initialize DSU
        DSU(int n) {
            size.resize(n + 1, 1); // Initialize size array
            parent.resize(n + 1);  // Initialize parent array

            // Everyone is its own parent initially
            for (int i = 0; i <= n; i++)
                parent[i] = i;
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
    // Function to check if two stones share the same row or column
    bool sameRowCol(vector<int> &a, vector<int> &b) {
        return (a[0] == b[0] || a[1] == b[1]);
    }

    int removeStones(vector<vector<int>>& stones) {
        int col = 0;
        int row = 0;
        int n = stones.size();
        
        // Find the maximum row and column values
        for (int i = 0; i < stones.size(); i++) {
            int c = stones[i][1];
            int r = stones[i][0];

            col = max(col, c);
            row = max(row, r);
        }

        // Initialize DSU with size enough to cover all rows and columns
        DSU d = DSU(col + row + 1);
        unordered_map<int, int> mp; // To check if stone in that row & col exist

        // Union the row and column of each stone
        for (int i = 0; i < stones.size(); i++) {
            int c = stones[i][1]; // Column index
            int r = stones[i][0] + col + 1; // Row index with offset to avoid overlap

            mp[c] = 1; // Mark the column as having a stone
            mp[r] = 1; // Mark the row as having a stone
            d.unionBySize(c, r); // Union the row and column in the DSU
        }

        int ultimateParents = 0;
        // Count unique ultimate parents in the map
        for (int i = 0; i < col + row + 1; i++) {
            if (mp.find(i) != mp.end() && d.parent[i] == i) 
                ultimateParents++;
        }

        // Number of stones that can be removed is total stones minus the number of unique components
        return n - ultimateParents;
    }
};
