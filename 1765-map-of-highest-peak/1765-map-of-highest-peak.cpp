class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        
        //we start bfs from all water
        queue< pair<pair<int,int>,int> > q;
        // <x,y>,height
        int n=isWater.size();
        int m=isWater[0].size();
        vector<vector<int>> grid(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(isWater[i][j]==1){
                    q.push({{i,j},0});
                }
            }
        }
        vector<vector<int>> dir={{-1,0},{0,1},{1,0},{0,-1}};
        //perform multi source bfs on them
        while(!q.empty()){
            auto it=q.front();
            q.pop();

            int x=it.first.first;
            int y=it.first.second;

            int h=it.second;

            for(int i=0;i<4;i++){
                int xi=x+dir[i][0];
                int yi=y+dir[i][1];

                if(xi>=0 && yi>=0 && xi<n && yi<m &&
                isWater[xi][yi]!=1 && grid[xi][yi]==0){
                    grid[xi][yi]=h+1;
                    q.push({{xi,yi},h+1});
                }
            }
        }

        return grid;
    }
};