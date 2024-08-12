class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n=nums.size();

        vector<int> zeroInd;
        int maxLen=0;
        int ind=0;
        int countZeroes=0;
        int l=0; int r=0;

        for(r=0;r<n;r++){
            if(nums[r]==0){
                countZeroes++;
                zeroInd.push_back(r);
            }

            if(countZeroes==k+1){
                maxLen=max(r-l,maxLen);
                l=zeroInd[ind]+1;
                ind++;
                countZeroes--;
            }
            else{
                maxLen=max(r-l+1,maxLen);
            }
        }

        return maxLen;
    }
};