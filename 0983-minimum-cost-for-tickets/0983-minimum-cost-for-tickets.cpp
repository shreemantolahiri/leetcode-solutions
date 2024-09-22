class Solution {
public:
    int dp[366];
    int solve(int ind,vector<int>& days, vector<int>& costs){
        if(ind==days.size()){
            return 0;
        }
        if(dp[ind]!=-1) return dp[ind];
        //we have three options
        //buy 1 day pass
        //we move to next index
        int oneDayPass=costs[0]+solve(ind+1,days,costs);
        
        //we can buy 7 day pass
        //we need to see how many index to skip
        int valid=days[ind]+6;
        int i=ind;
        while(i<days.size() && days[i]<=valid) i++;

        //i is at first invalid day
        int sevenDayPass=costs[1]+solve(i,days,costs);

        //we buy 30 day pass
        valid=days[ind]+29;
        i=ind;
        while(i<days.size() && days[i]<=valid) i++;
        int thirtyDayPass=costs[2]+solve(i,days,costs);

        return dp[ind]=min({oneDayPass,sevenDayPass,thirtyDayPass});
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        // int n=days.size();
        memset(dp,-1,sizeof(dp));
        return solve(0,days,costs);
    }
};