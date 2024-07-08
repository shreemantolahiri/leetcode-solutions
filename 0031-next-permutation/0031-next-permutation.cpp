class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n=nums.size();
        int i=n-2;
        for(i=n-2;i>=0;i--){
            if(nums[i+1]<=nums[i]) continue;
            else break;
        }
        if(i==-1){
            sort(nums.begin(),nums.end());
        }
        else{
            //we break at index i
            cout<<nums[i]<<endl;
            //find number larger than nums[i]
            int j=i+1; int ind=i+1;
            for(int k=i+2;k<n;k++){
                if(nums[k]>nums[i] && nums[k]<nums[j]){
                    j=k;
                }
            }

            swap(nums[i],nums[j]);

            sort(nums.begin()+i+1,nums.end());
        }
    }
};