class Solution {
public:
    bool isPossible(vector<int>& nums,int maxSize,int maxOperations){
        int buckets=0;

        for(int i=0;i<nums.size();i++){
            buckets+=nums[i]/maxSize;
            if(nums[i]%maxSize!=0) buckets++;
        }

        if(buckets-nums.size()>maxOperations) return false;

        return true;
    }
    int minimumSize(vector<int>& nums, int maxOperations) {
        int low=1;
        int high=INT_MIN;

        for(auto it:nums) high=max(high,it);
        cout<<low<<" "<<high<<endl;

        while(low<=high){
            int mid=low+(high-low)/2;

            if(isPossible(nums,mid,maxOperations)){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }

        return low;
    }
};