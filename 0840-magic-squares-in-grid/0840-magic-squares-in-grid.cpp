class Solution {
public:
    bool check(int i,int j,vector<vector<int>>& grid){
        int n=grid.size();
        int m=grid[0].size();
        if(m-j<3 || n-i<3) return false;

        vector<int> isPresent(10,0);
        //check rows
        int prev=-1;
        for(int row=i;row<i+3;row++){
            int curr=0;
            for(int col=j;col<j+3;col++){
                if(grid[row][col]<1 || grid[row][col]>9) return false;
                if(isPresent[grid[row][col]]==1) 
                return false;
                else{
                    isPresent[grid[row][col]]=1;
                }
                curr+=grid[row][col];
            }
            if(prev==-1) prev=curr;
            else{
                if(prev!=curr) return false;
                prev=curr;
            }
        }
        //check cols
        prev=-1;
        for(int cols=j;cols<j+3;cols++){
            int curr=0;
            for(int rows=i;rows<i+3;rows++){
                curr+=grid[rows][cols];
            }
            if(prev==-1) prev=curr;
            else{
                if(prev!=curr) return false;
                prev=curr;
            }
        }

        //check diagonals
        int diag1=grid[i][j]+grid[i+1][j+1]+grid[i+2][j+2];
        int diag2=grid[i][j+2]+grid[i+1][j+1]+grid[i+2][j];

        if(diag1!=diag2) return false;
        return true;

    }
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int i=0;
        int n=grid.size();
        int m=grid[0].size();
        int count=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(check(i,j,grid)) count++;
            }
        }

        return count;
    }
};