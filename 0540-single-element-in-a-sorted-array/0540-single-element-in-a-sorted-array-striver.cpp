class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return nums[0];

        //trim down the search space so that NEVER out of bound
        int left=1;
        int right=n-2;

        //base conditions for edge cases
        if(nums[0]!=nums[1]) return nums[0];

        if(nums[n-1]!=nums[n-2]) return nums[n-1];
        while(left<=right){
            int mid=left+(right-left)/2;

            
        
            //middle element && ans
            if(nums[mid-1]!=nums[mid] && nums[mid]!=nums[mid+1]) return nums[mid];

            else{
                //we check the odd even
                if(nums[mid]==nums[mid+1]){
                    if(mid%2==0) left=mid+1;
                    else right=mid-1;
                }
                else{
                    if((mid-1)%2==0) left=mid+1;
                    else right=mid-1;
                }
            }
        }

        return -1;
    }
};