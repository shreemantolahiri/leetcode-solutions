class Solution {
public:
    int solve(vector<int>& nums, int k){
        if(k<0) return 0;
        int n=nums.size();
        int left=0,right=0;

        int odds=0;
        int count=0;
        for(;right<n;right++){
            if(nums[right]%2!=0) odds++; //odd number

            while(odds>k){
                if(nums[left]%2!=0) odds--;
                left++;
            }

            //we have subarray from left..right ->find subarrays 
            count+=right-left+1;
        }

        return count;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        return solve(nums,k) - solve(nums,k-1);
    }
};