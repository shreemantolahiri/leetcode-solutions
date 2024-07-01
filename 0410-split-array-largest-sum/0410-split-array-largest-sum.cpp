class Solution {
public:
    bool canBeSplit(vector<int>& nums, int k,long long maxSum){
        int currSum=nums[0];
        int painters=1;
        for(int i=1;i<nums.size();i++){
            if(k<painters) break;
            if(currSum+nums[i]<=maxSum){
                currSum+=nums[i];
            }
            else{
                // k--;
                painters++;
                currSum=nums[i];
            }
        }

        if(painters<=k) return true;
        return false;
    }
    int splitArray(vector<int>& nums, int k) {
        int left=INT_MIN; 
        long long right=0;

        for(int i=0;i<nums.size();i++){
            left=max(left,nums[i]);
            // right=max(right,(long long)nums[i]);
            right+=nums[i];
        }

        while(left<=right){
            long long mid=left+(right-left)/2;

            if(canBeSplit(nums,k,mid)){
                right=mid-1;
            }
            else{
                left=mid+1;
            }
        }

        return left;
    }
};