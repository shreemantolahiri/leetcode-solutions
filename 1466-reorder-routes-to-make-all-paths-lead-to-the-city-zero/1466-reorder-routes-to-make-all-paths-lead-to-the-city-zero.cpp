class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        unordered_set<int> vis;
        int count=0;
        unordered_map<int,vector<int>> adj;
        vector<unordered_set<int>> arrow(n);
        for(auto it:connections){
            arrow[it[0]].insert(it[1]);
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }

        
        queue<int> q;
        q.push(0);
        vis.insert(0);
        while(!q.empty()){
            int node=q.front(); 
            // cout<<node<<endl;
            q.pop();

            for(auto v:adj[node]){
                if(vis.count(v)==0){
                    q.push(v);
                    vis.insert(v);

                    //check arrow
                    if(arrow[node].count(v)!=0) count++;
                }
            }
        }

        return count;
    }
};