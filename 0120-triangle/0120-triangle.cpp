class Solution {
public:
    int dp[201][201];
    int solve(int i,int j,vector<vector<int>>& triangle){
        if(i>=triangle.size() || j<0 || j>=triangle[i].size())
        return 0;
        
        
        //we are at i and j 
        if(dp[i][j]!=-1) return dp[i][j];
        //two choices
        int down=triangle[i][j]+solve(i+1,j,triangle);
        
        int rightDown=triangle[i][j]+solve(i+1,j+1,triangle);
        // cout<<down<<" "<<rightDown<<endl;
        return dp[i][j]=min(down,rightDown);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        
        // vector<vector<int>> dp(triangle.size()+1,vector<int>(triangle.size()+1,-1));
        memset(dp,-1,sizeof(dp));
        return solve(0,0,triangle);
    }
};