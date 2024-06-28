class Solution {
public:
    int findMin(vector<int>& nums) {
        int n=nums.size();
        int left=0;
        int right=n-1;
        int mini=nums[0];
        while(left<=right){
            int mid=left+(right-left)/2;
            cout<<nums[mid]<<endl;
            if(nums[left]<=nums[mid]){
                //left is sorted
                mini=min(mini,nums[left]);
                //move right
                left=mid+1;
            }
            else{
                //right is sorted
                mini=min(mini,nums[mid]);
                right=mid-1;
            }
        }

        return mini;
    }
};