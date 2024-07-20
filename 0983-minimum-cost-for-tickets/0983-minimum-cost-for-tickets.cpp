class Solution {
public:
    int dp[366][1600];
    int solve(int ind,int valid,vector<int>& days, vector<int>& costs){
        if(ind==days.size()){
            return 0;
        }
        if(dp[ind][valid]!=-1) return dp[ind][valid];
        //if day is valid just continue
        if(valid>=days[ind]) 
        return dp[ind][valid]=solve(ind+1,valid,days,costs);

        else{
            //have to buy
            return dp[ind][valid]=min({
                solve(ind+1,days[ind],days,costs)+costs[0],
                solve(ind+1,days[ind]+6,days,costs)+costs[1],
                solve(ind+1,days[ind]+29,days,costs)+costs[2]

            });
        }
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        memset(dp,-1,sizeof(dp));
        return solve(0,0,days,costs);
    }
};