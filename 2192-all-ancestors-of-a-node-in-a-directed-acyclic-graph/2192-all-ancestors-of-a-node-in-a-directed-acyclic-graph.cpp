class Solution {
public:
    void dfs(int par,unordered_map<int,vector<int>> &adj,map<int,set<int>> &mp,int n){
        vector<int> vis(n,0);
        vis[par]=1;
        queue<int> q;
        q.push(par);
        // cout<<par<<" parent"<<endl;
        while(!q.empty()){
            int v=q.front();
            q.pop();

            for(auto it:adj[v]){
                if(!vis[it]){
                    mp[it].insert(par);
                    // cout<<it<<" has ancestor= "<<par<<endl;
                    vis[it]=1;
                    q.push(it);
                }
            }
        }

        return;
    }
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        map<int,set<int>> mp;
        unordered_map<int,vector<int>> adj;

        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            // cout<<edges[i][0]<<"  "<<edges[i][1]<<endl;
        }

        //we perform dfs over every element
        for(int i=0;i<n;i++){
            dfs(i,adj,mp,n);
        }

        //final result
        vector<vector<int>> res(n);
        
        int index = 0;

        for (int i=0;i<n;i++) {
        // Convert set<int> to vector<int>
        if(mp.find(i)==mp.end()) continue;
        res[i] = vector<int>(mp[i].begin(), mp[i].end());
        }

        return res;

    }
};