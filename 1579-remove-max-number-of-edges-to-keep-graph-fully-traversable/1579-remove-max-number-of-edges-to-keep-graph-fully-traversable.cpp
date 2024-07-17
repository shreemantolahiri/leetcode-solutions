class Solution {
    class DSU {
    public:
        vector<int> size, parent, rank;

        // Constructor to initialize DSU
        DSU(int n) {
            size.resize(n + 1, 1); // Initialize size array
            parent.resize(n + 1);  // Initialize parent array
            rank.resize(n + 1, 0); // Initialize rank array

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

        // Union two nodes by rank
        void unionByRank(int u, int v) {
            int uPar = findUltPar(u);
            int vPar = findUltPar(v);

            if (uPar == vPar) return; // If they already have the same parent, do nothing

            // Perform union by rank
            if (rank[uPar] < rank[vPar]) {
                parent[uPar] = vPar;
            } else if (rank[uPar] > rank[vPar]) {
                parent[vPar] = uPar;
            } else {
                parent[vPar] = uPar;
                rank[uPar]++;
            }
        }
    };

public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        DSU a = DSU(n+1); // DSU for Alice
        DSU b = DSU(n+1); // DSU for Bob

        // Sort edges in descending order to process type 3 edges first
        sort(edges.begin(), edges.end(), greater<>());
        int count = 0; // To count the number of removable edges

        for (int i = 0; i < edges.size(); i++) {
            int type = edges[i][0];
            int u = edges[i][1];
            int v = edges[i][2];

            if (type == 1) {
                // Type 1: Check in Alice's DSU
                int up = a.findUltPar(u);
                int vp = a.findUltPar(v);
                if (up == vp) {
                    // If u and v are already connected, this edge is redundant
                    count++;
                } else {
                    // Otherwise, union them
                    a.unionBySize(u, v);
                }
            } else if (type == 2) {
                // Type 2: Check in Bob's DSU
                int up = b.findUltPar(u);
                int vp = b.findUltPar(v);
                if (up == vp) {
                    // If u and v are already connected, this edge is redundant
                    count++;
                } else {
                    // Otherwise, union them
                    b.unionBySize(u, v);
                }
            } else {
                // Type 3: Check in both DSUs
                int Aup = a.findUltPar(u);
                int Avp = a.findUltPar(v);
                int Bup = b.findUltPar(u);
                int Bvp = b.findUltPar(v);

                if (Aup == Avp && Bup == Bvp) {
                    // If u and v are already connected in both DSUs, this edge is redundant
                    count++;
                } else {
                    // Otherwise, union them in both DSUs
                    a.unionBySize(u, v);
                    b.unionBySize(u, v);
                }
            }
        }

        // Check if both graphs are fully traversable
        bool isATraversable = false;
        bool isBTraversable = false;
        for (int i = 1; i <= n; i++) {
            // Check if there is only one connected component in each DSU
            if (a.parent[i] == i && a.size[i] == n) isATraversable = true;
            if (b.parent[i] == i && b.size[i] == n) isBTraversable = true;
        }

        // If either graph is not fully traversable, return -1
        if (!isATraversable || !isBTraversable) return -1;

        // Otherwise, return the count of removable edges
        return count;
    }
};
