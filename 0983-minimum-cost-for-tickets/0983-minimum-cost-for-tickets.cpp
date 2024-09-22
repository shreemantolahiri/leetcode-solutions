class Solution {
public:
    int dp[366];
    int nextIndex(int day, vector<int>& days){
        int ind=lower_bound(days.begin(),days.end(),day)-days.begin();
        cout<<day<<" index= "<<ind<<endl;
        return ind;
    }
    int solve(int ind, vector<int>& days, vector<int>& costs){
        if(ind>=days.size()) return 0;

        //check dp
        if(dp[ind]!=-1) return dp[ind];
        //we are at day(ind)
        //buy 1 day pass
        int oneDay=costs[0]+solve(ind+1,days, costs);

        //7 day pass
        //how much should indexJump by
        int indexJumpsBy=nextIndex(days[ind]+7,days);
        int sevenDay=costs[1]+solve(indexJumpsBy,days,costs);
        //one monthpass
        indexJumpsBy=nextIndex(days[ind]+30,days);
        int thirtyDay=costs[2]+solve(indexJumpsBy,days,costs);

        return dp[ind]=min({oneDay,sevenDay,thirtyDay});
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        memset(dp,-1,sizeof(dp));
        return solve(0,days,costs);
    }
};