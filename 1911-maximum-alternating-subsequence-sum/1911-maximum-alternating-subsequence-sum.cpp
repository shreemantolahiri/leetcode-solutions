class Solution {
public:
    long long dp[100001][2];
    long long solve(int ind,bool isEven,vector<int> &nums){
        if(ind==nums.size()-1){
            if(isEven) return nums[ind];
            else return 0;
        }
        if(dp[ind][isEven]!=-1) return dp[ind][isEven];
        //if even we add
        long long pick=0;
        if(isEven) pick=solve(ind+1,!isEven,nums)+nums[ind];
        else{
            pick=solve(ind+1,!isEven,nums)-nums[ind];
        }

        long long skip=solve(ind+1,isEven,nums);


        return dp[ind][isEven]=max(pick,skip);
    }
    long long maxAlternatingSum(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        return solve(0,true,nums);
    }
};