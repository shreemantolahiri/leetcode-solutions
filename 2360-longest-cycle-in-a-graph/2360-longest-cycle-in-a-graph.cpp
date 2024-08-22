class Solution {
public:
    vector<int> vis;
    vector<int> pos;

    int dfs(int node,int p,vector<int>& edges){
        //if we come across already visited node stop
        if(vis[node]>=0) return 0;
        if(pos[node]!=0){
            //cycle found
            return abs(pos[node]-p);
        }

        //not yet explored
        int ans=0;
        pos[node]=p;
        if(edges[node]!=-1) ans=dfs(edges[node],p+1,edges);
        pos[node]=0;
        vis[node]=ans;
        return ans;
    }

    int longestCycle(vector<int>& edges) {
        int n=edges.size();
        vis.resize(n,-1);
        pos.resize(n,0);

        int ans=-1;
        for(int i=0;i<n;i++){
            if(vis[i]==-1){
                int res=dfs(i,1,edges);
                if(res>0) ans=max(ans,res);
            }
        }

        return ans;
    }
};