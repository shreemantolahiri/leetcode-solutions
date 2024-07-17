class Solution {
public:
    bool isAnExit(int i,int j,int n,int m){
        if(i==0 || j==0 || i==n-1 || j==m-1) return true;

        return false;
    }
    vector<int> dx={-1,0,1,0},dy={0,1,0,-1};

    int bfs(int i,int j,vector<vector<char>>& maze){
        int n=maze.size();
        int m=maze[0].size();
        queue<pair<int,pair<int,int>>> q;
        //dist,{i,j}
        q.push({0,{i,j}});
        maze[i][j]='+';
        while(!q.empty()){
            auto it=q.front();
            q.pop();
            int dist=it.first;
            int x=it.second.first;
            int y=it.second.second;
            if(isAnExit(x,y,n,m) && !(x==i && y==j)){
                return dist;
            }
                //we try all four directions
                for(int k=0;k<4;k++){
                    int newx=x+dx[k];
                    int newy=y+dy[k];
                if(newx>=0 && newx<n && newy>=0 && newy<m && maze[newx][newy]!='+'){
                    q.push({dist+1,{newx,newy}});
                    maze[newx][newy]='+';
                }
                }
            
        }

        return -1;
    }
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        //apply bfs
        int i=entrance[0];
        int j=entrance[1];


        return bfs(i,j,maze);
    }
};