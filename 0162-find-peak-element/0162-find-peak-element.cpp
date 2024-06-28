class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n=nums.size();

        
        if(n==1) return 0;
        if(nums[0]>nums[1]) return 0;
        if(nums[n-1]>nums[n-2]) return n-1;

        //we trim the edges as 0 and n-1 are covered
        int left=1; int right=n-2;
        while(left<=right){
            int mid=left+(right-left)/2;
            cout<<nums[mid]<<endl;
            //edge cases
            if(nums[mid-1]<nums[mid] && nums[mid]>nums[mid+1]) return mid;

            else if(nums[mid-1]<nums[mid]){
                //increasing slope so move right
                left=mid+1;
            }
            else{
                //decreasing slope so move left
                right=mid-1;
            }
        }

        return -1;
    }
};