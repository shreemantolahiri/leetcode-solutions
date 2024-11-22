class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n=nums.size();

        sort(nums.begin(),nums.end());
        int left=0,right=n-1;
        if(n==1) return nums[0];
        while(left<=right){
            int mid=left+(right-left)/2;
            
            //check if its answer
            //left checker
            if((mid==0 || (nums[mid-1]!=nums[mid])) && 
            (mid==n-1 || (nums[mid+1]!=nums[mid]))){
                return nums[mid];
            }
            //check where its duplicate exists
            if(mid>0){
                if(nums[mid-1]==nums[mid]){
                    if((mid-1)%2==0){
                        //sorted hai move right
                        left=mid+1;
                        continue;
                    }
                    else{
                        right=mid-1;
                        continue;
                    }
                }
            }
            if(mid<n){
                if(nums[mid+1]==nums[mid]){
                    if(mid%2==0){
                        //sorted hai move right
                        left=mid+1;
                        continue;
                    }
                    else{
                        right=mid-1;
                        continue;
                    }
                }
            }
            
        }
        
        
        
        return -1;
    }
};