class Solution {
public:
    int dp[41][41];
    int solve(int i, int j,vector<int>& arr){
        if(i>j) return 0;
        if(i==j){
            return 0;
        }
        if(dp[i][j]!=-1) return dp[i][j];
        int sum=1e7;
        for(int k=i;k<j;k++){
            //left max
            int leftMax=arr[i];
            for(int u=i;u<=k;u++) leftMax=max(leftMax,arr[u]);

            int rightMax=arr[j];
            for(int u=k+1;u<=j;u++) rightMax=max(rightMax,arr[u]);
            // cout<<leftMax<<" "<<rightMax<<endl;
            // cout<<i<<" "<<j<<endl;
            int ans=leftMax*rightMax+solve(i,k,arr)+solve(k+1,j,arr);
            sum=min(sum,ans);
        }

        return dp[i][j]=sum;
    }
    int mctFromLeafValues(vector<int>& arr) {
        memset(dp,-1,sizeof(dp));

        return solve(0,arr.size()-1,arr);
    }
};