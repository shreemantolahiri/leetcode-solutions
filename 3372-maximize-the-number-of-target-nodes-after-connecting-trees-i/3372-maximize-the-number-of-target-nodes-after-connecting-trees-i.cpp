class Solution {
public:
    vector<vector<int>> buildAdj(const vector<vector<int>>& edges) {
        int n = edges.size() + 1; 
        vector<vector<int>> adjList(n);
        for (const auto& edge : edges) {
            adjList[edge[0]].push_back(edge[1]);
            adjList[edge[1]].push_back(edge[0]);
        }
        return adjList;
    }

    vector<int> findNeighbours(vector<vector<int>> &tree1,int k){
        //start bfs
        int n=tree1.size();
        queue<pair<int,int>> q;
        vector<int> neighbours(n,0);
        
        
        for(int i=0;i<n;i++){
            //start node=i
            vector<int> vis(n,0);
            vis[i]=1;
            q.push({i,0});
            
            while(!q.empty()){
            int node=q.front().first;
            int dist=q.front().second;
            q.pop();
                
            if(dist<=k) neighbours[i]++;
            else continue;
            
            
            for(auto it:tree1[node]){
                if(vis[it]==0){
                    q.push({it,dist+1});
                    vis[it]=1;
                }
            }
        }
        }
        
        
        
        
        
        return neighbours;
    }
    
    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2, int k) {
        vector<vector<int>> tree1 = buildAdj(edges1);
        vector<vector<int>> tree2 = buildAdj(edges2);
        
        //find number of neighbours for all nodes in tree1 less than k
        vector<int> tree1Neighbours=findNeighbours(tree1,k);
        
        vector<int> tree2Neighbours=findNeighbours(tree2,k-1);
        
        int maxNInTree2=0;
        
        for(auto it:tree2Neighbours) maxNInTree2=max(maxNInTree2,it);
        
        vector<int> res;
        for(int i=0;i<tree1.size();i++){
            int count=0;
            
            count+=tree1Neighbours[i];
            count+=maxNInTree2;
            
            res.push_back(count);
        }
        
        
        return res;
        
        
       
    }
};