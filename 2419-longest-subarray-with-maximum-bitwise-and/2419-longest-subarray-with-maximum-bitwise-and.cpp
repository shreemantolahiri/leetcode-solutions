class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int maxElement=0;
        int n=nums.size();


        for(int i=0;i<n;i++){
            maxElement=max(maxElement,nums[i]);
        }
        cout<<maxElement<<endl;
        int maxLen=1;
        int count=1;
        for(int i=1;i<n;i++){
            if(nums[i]==maxElement && nums[i-1]==nums[i]) {
                count++;
                maxLen=max(maxLen,count);
            }
            else{
                count=1;
            }

            
        }

        return maxLen;

    }
};