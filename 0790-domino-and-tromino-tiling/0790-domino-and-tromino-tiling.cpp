class Solution {
public:
    int dp[1001];
    int solve(int n){
        if(n==0) return 1;
        if(n==1 || n==2) return n;
        if(dp[n]!=-1) return dp[n];
        return dp[n]=(solve(n-3)+2*solve(n-1))% 1000000007;
    }
    int numTilings(int n) {
        memset(dp,-1,sizeof(dp));
        return solve(n)% 1000000007;
    }
};