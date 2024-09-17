class Solution {
public:
    int n;
    int dp[100001][27];
    int solve(int ind,int ch,string &s, int k){
        if(ind==n) return 0;
        if(dp[ind][ch]!=-1) return dp[ind][ch];
        //if we can pick
        int num=s[ind]-'a'+1;
        int pick=0;
        if(ch==0 || abs(num-ch)<=k){
            pick=1+solve(ind+1,num,s,k);
        }
        //skip
        int skip=solve(ind+1,ch,s,k);

        return dp[ind][ch]=max(pick,skip);
    }
    int longestIdealString(string s, int k) {
        n=s.length();
        memset(dp,-1,sizeof(dp));
        return solve(0,0,s,k);
    }
};