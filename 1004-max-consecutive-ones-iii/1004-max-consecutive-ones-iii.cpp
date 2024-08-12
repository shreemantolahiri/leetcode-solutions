class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int zeroes=0;
        int n=nums.size();
        int l=0;
        int maxLen=0;
        for(int r=0;r<n;r++){
            if(nums[r]==0){
                zeroes++;
            }
            if(zeroes<=k){
                maxLen=max(r-l+1,maxLen);
            }
            else{
                if(nums[l]==0){
                    zeroes--;
                }
                l++;
            }

        }

        return maxLen;
    }
};