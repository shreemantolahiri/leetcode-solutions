class Solution {
public:
    long long dfs(int node,
    unordered_map<int,vector<int>>& adj,
    vector<int> &visited){
        visited[node]=1;
        long long visits=1;
        for(auto &v:adj[node]){
            if(!visited[v]){
                visited[v]=1;
                visits+=dfs(v,adj,visited);
            }
        }

        return visits;
    }
    long long countPairs(int n, vector<vector<int>>& edges) {
        //find number of components
        vector<int> visited(n,0);
        // if(edges.size()<=1) return 0;
        unordered_map<int,vector<int>> adj;

        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        vector<int> components;
        for(int i=0;i<n;i++){
            long long c=0;
            if(!visited[i]) c=dfs(i,adj,visited);

            if(c>0) components.push_back(c);
        }
        long long total=n; //if everything was disconnected
        long long res=total*(total-1)/2;
        if(components.size()<=1) return 0;
        else{
            //multiply total
            // long long ans=0;
            // for(int j=0;j<components.size();j++){
            //     for(int i=j+1;i<components.size();i++){
            //         ans+=(long long)components[i]*components[j];
            //     }
            // }
            for(int i=0;i<components.size();i++){
                long long k=components[i];
                res=res-k*(k-1)/2;
            }

            return res;
        }

    }
};