class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return nums[0];
        int left=0;
        int right=n-1;

        while(left<=right){
            int mid=left+(right-left)/2;

            //first element
            if(mid==0 && nums[mid]!=nums[mid+1]) return nums[mid];

            //last element
            else if(mid==n-1 && nums[mid-1]!=nums[mid]) return nums[mid];
        
            //middle element && ans
            else if(nums[mid-1]!=nums[mid] && nums[mid]!=nums[mid+1]) return nums[mid];


            //did not get an answer
            else if(mid==0){
                //means 0 and 1 are same
                left=mid+1;
            }
            else if(mid==n-1){
                right=mid-1;
            }
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