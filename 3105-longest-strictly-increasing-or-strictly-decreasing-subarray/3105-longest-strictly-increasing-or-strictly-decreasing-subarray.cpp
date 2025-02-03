class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n=nums.size();


        //mono inc
        int len=1;
        int longest=1;
        for(int i=1;i<n;i++){
            if(nums[i-1]<nums[i]) len++;
            else len=1;

            longest=max(longest,len);
        }
        len=1;
        //dec
        for(int i=1;i<n;i++){
            if(nums[i-1]>nums[i]) len++;
            else len=1;

            longest=max(longest,len);
        }

        return longest;
    }
};