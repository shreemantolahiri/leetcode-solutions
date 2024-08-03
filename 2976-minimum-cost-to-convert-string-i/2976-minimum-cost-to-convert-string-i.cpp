class Solution {
public:
    //prims algorithm
    void floydWarshall(vector<vector<int>> &adj) {
        int V = adj.size();
        for (int k = 0; k < V; k++) {
            for (int i = 0; i < V; i++) {
                for (int j = 0; j < V; j++) {
                    if (adj[i][k] != INT_MAX && adj[k][j] != INT_MAX) {
                        adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
                    }
                }
            }
        }
    }
    long long minimumCost(string source, 
    string target, vector<char>& original, 
    vector<char>& changed, 
    vector<int>& cost) {
        vector<vector<int>> adj(26,vector<int>(26,INT_MAX));
        int n=original.size();

        for(int i=0;i<n;i++){
            char src=original[i];
            char dst=changed[i];
            int c=cost[i];

            //shortest path
            adj[src-'a'][dst-'a']=min(c,adj[src-'a'][dst-'a']);
            
        }
        floydWarshall(adj);
        long long res=0;
        for(int i=0;i<source.length();i++){
            if(source[i]==target[i]) continue;
            else{
                //cannot be reached
                if(adj[source[i]-'a'][target[i]-'a']==INT_MAX) return -1;
                res+=adj[source[i]-'a'][target[i]-'a'];
            }
        }
        return res;
    }
};