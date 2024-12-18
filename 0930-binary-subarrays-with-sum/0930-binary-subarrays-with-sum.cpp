class Solution {
public:
    int subLessThanK(vector<int>& nums, int k){
        int left=0,right=0;

        int n=nums.size();
        int sum=0;

        int count=0;
        for(;right<n;right++){
            sum+=nums[right];
            cout<<left<< " "<<right<<endl;
            while(sum>k && left<=right){
                sum-=nums[left];
                left++;
            }

            count+=right-left+1;
        }

        return count;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        if(goal==0) return subLessThanK(nums,goal);
        return subLessThanK(nums,goal) - subLessThanK(nums,goal-1);
    }
};