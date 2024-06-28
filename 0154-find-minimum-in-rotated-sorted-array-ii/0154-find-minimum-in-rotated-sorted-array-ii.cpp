class Solution {
public:
    int findMin(vector<int>& nums) {
        int n=nums.size();
        int left=0;
        int right=n-1;
        int mini=INT_MAX;
        while(left<=right){
            int mid=left+(right-left)/2;

            if(nums[left]==nums[mid] && nums[mid]==nums[right]){
                mini=min(nums[mid],mini);
                left++;
                right--;
            }
            else if(nums[left]<=nums[mid]){
                //left sorted
                mini=min(nums[left],mini);
                left=mid+1;
            }
            else{
                //right is sorted
                mini=min(nums[mid],mini);
                right=mid-1;
            }
        }

        return mini;
    }
};