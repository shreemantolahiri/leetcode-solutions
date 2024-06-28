class Solution {
public:
    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
        vector<vector<int>>adj(n+1);
        for(auto i : paths){
            adj[i[0]-1].push_back(i[1]-1);
            adj[i[1]-1].push_back(i[0]-1);
        }
        
        vector<int>color(n,0);
        for(int i=0;i<n;i++){
            if(color[i]==0){
                color[i]=1;
                queue<int>q;
                q.push(i);
                while(!q.empty()){
                    int curr = q.front();
                    q.pop();
                    for(auto j : adj[curr]){
                        if(color[j]==0 || color[j]==color[curr]){
                            color[j] = color[curr]+1;
                            q.push(j);
                        }
                        if(color[j]>4) color[j]%=4;
                    }
                }
                // for(auto l : color) cout<<l<<" ";
                // cout<<"\n";
            }
        }
        return color;
    }
};