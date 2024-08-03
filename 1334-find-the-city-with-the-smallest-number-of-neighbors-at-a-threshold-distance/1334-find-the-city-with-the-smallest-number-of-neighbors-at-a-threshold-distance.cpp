class Solution {
public:
    void floydWarshall(vector<vector<int>> &adj){
        int n=adj.size();

        for(int k=0;k<n;k++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if(adj[i][k]!=INT_MAX && adj[k][j]!=INT_MAX){
                        adj[i][j]=min(adj[i][j],adj[i][k]+adj[k][j]);
                    }
                }
            }
        }
    }
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> adj(n,vector<int>(n,INT_MAX));

        for(int i=0;i<edges.size();i++){
            int a=edges[i][0];
            int b=edges[i][1];
            int c=edges[i][2];

            adj[a][b]=c;
            adj[b][a]=c;
        }

        floydWarshall(adj);
        int minCities=INT_MAX;
        int city=-1;
        //now we traverse the nodes
        for(int i=0;i<n;i++){
            int count=0;
            for(int j=0;j<n;j++){
                if(i==j) continue;
                else{
                    if(adj[i][j]<=distanceThreshold) count++;
                }
            }

            if(count<minCities){
                minCities=count;
                city=i;
            }
            else if(count==minCities){
                city=i;
            }
        }

        return city;
    }
};