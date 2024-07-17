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
        DSU a=DSU(n+1);
        DSU b=DSU(n+1);

        int count=0;
        for(int i=0;i<edges.size();i++){
            int type=edges[i][0];
            int u=edges[i][1];
            int v=edges[i][2];
            if(type==1){
                //check in a
                int up=a.findUltPar(u);
                int vp=a.findUltPar(v);
                if(up==vp){
                    count++;
                }
                else{
                    a.unionBySize(u,v);
                    continue;
                }
            }
            else if(type==2){
                //check in b
                int up=b.findUltPar(u);
                int vp=b.findUltPar(v);
                if(up==vp){
                    count++;
                }
                else{
                    b.unionBySize(u,v);
                    continue;
                }
            }
            else{
                //check in a
                int Aup=a.findUltPar(u);
                int Avp=a.findUltPar(v);
                int Bup=b.findUltPar(u);
                int Bvp=b.findUltPar(v);

                if(Aup==Avp && Bup==Bvp){
                    count+=2;
                }
                else{
                    a.unionBySize(Aup,Avp);
                    b.unionBySize(Bup,Bvp);
                    continue;
                }
            }
        }

        //is the graph traversable or not
        bool isATraversable=false;
        bool isBTraversable=false;
        for(int i=1;i<=n;i++){
            //check if size is n or not
            if(a.parent[i]==i && a.size[i]==n) isATraversable=true;
            if(b.parent[i]==i && b.size[i]==n) isBTraversable=true;
        }

        if(!isATraversable || !isBTraversable) return -1;

        else return count;
    }
};