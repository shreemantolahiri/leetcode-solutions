class Solution {
public:
    void topoSort(vector<int> &ind,unordered_map<int,vector<int>> &adj){
	    queue<int> q;
	    
	    for(int i=0;i<ind.size();i++){
	        if(ind[i]==0){
	            q.push(i);
	        }
	    }
	    
	    while(!q.empty()){
	       int node=q.front();
	      
	    //    res.push_back(node);
	       q.pop();
	       for(auto it:adj[node]){
	           // cout<<adj[i][j]<<endl;
	           // int to=adj[node][j];
	            
	            ind[it]--;
	            if(ind[it]==0){
	                q.push(it);
	            }
	        }
	        
	    }
	    
	    return;
	}
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int,vector<int>> adj;
        vector<int> visited(numCourses,0);
        vector<int> indegree(numCourses,0);
        for(auto &v:prerequisites){
            adj[v[0]].push_back(v[1]);
            indegree[v[1]]++;
        }
        topoSort(indegree,adj);
        //check if all indegrees are 0
        for(int i=0;i<numCourses;i++){
            if(indegree[i]>0) return false;
        }
        return true;

    }
};