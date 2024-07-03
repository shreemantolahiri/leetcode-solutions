class Solution {
public:
    int minDifference(vector<int>& nums) {
        int n=nums.size();

        if(n<=4) return 0;
        int i=0; int j=n-1;
        sort(nums.begin(),nums.end());
        int ans=INT_MAX;
        for(int left=0;left<=3;left++){
            int right=3-left;

            ans=min(ans,nums[j-right]-nums[i+left]);
        }

        return ans;
    }
};