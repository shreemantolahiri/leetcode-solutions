class Solution {
public:
    int dp[100001][2];
    int solve(int ind, int crossedB, string& s) {
        if (ind == s.length())
            return 0;
        if(dp[ind][crossedB]!=-1) return dp[ind][crossedB];
        if (s[ind] == 'a') {
            // if we get a after crossingB
            if (crossedB)
                return dp[ind][crossedB]=1 + solve(ind + 1, crossedB, s);

            // if we did not get b
            return dp[ind][crossedB]=solve(ind + 1, crossedB, s);
        } else {
            if (crossedB) {
                // already crossed B
                return dp[ind][crossedB]=solve(ind + 1, crossedB, s);
            } else {
                // we can remove it
                int op1 = 1 + solve(ind + 1, 0, s);

                // we can consider b
                int op2 = solve(ind + 1, 1, s);

                return dp[ind][crossedB]=min(op1, op2);
            }
        }
    }
    int minimumDeletions(string s) { 
        memset(dp,-1,sizeof(dp));
        return solve(0, 0, s); 
        }
};