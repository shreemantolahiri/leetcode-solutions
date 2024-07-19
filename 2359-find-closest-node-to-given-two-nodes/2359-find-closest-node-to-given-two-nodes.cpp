class Solution {
public:
    void bfs(int node, vector<int>& dist, vector<int>& edges) {
        unordered_set<int> vis;

        queue<int> q;
        q.push(node);
        vis.insert(node);
        int lvl = 0;
        while (!q.empty()) {
            int sz = q.size();

            for (int i = 0; i < sz; i++) {
                int curr = q.front();
                q.pop();
                if(dist[curr]==-1) dist[curr]=lvl;

                int nextNode=edges[curr];
                if(nextNode!=-1 && vis.find(nextNode)==vis.end()){
                    q.push(nextNode);
                    vis.insert(nextNode);
                }
            }

            lvl++;
        }

        return;
    }
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n = edges.size();

        vector<int> dist1(n + 1, -1), dist2(n + 1, -1);
        bfs(node1,dist1,edges);
        bfs(node2,dist2,edges);

        // for(auto it:dist1) cout<<it<<" ";
        // cout<<endl;
        // for(auto it:dist2) cout<<it<<" ";
        // cout<<endl;
        int minDist=INT_MAX; int node=-1;
        for(int i=0;i<=n;i++){
            if(dist1[i]!=-1 && dist2[i]!=-1){
                if(minDist>max(dist1[i],dist2[i])){
                    node=i;
                    minDist=max(dist1[i],dist2[i]);
                }
            }
        }
        return node;
        // start dfs from node1
    }
};