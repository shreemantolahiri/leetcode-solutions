class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        vector<int> dp(n,1); //atleast length of 1
        vector<int> hash(n,0);
        int maxi=0;
        int lastIndex=0;
        //initializing hash
        for(int i=0;i<n;i++){
            hash[i]=i;
        }

        //O(N^2)
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[i]%nums[j]==0 || nums[j]%nums[i]==0){
                    if(1+dp[j]>dp[i]){
                        dp[i]=1+dp[j];
                        hash[i]=j;

                        if(maxi<dp[i]){
                            maxi=dp[i];
                            lastIndex=i;
                        }
                    }
                }
            }
        }

        vector<int> res;
        while(lastIndex!=hash[lastIndex]){
            res.push_back(nums[lastIndex]);
            lastIndex=hash[lastIndex];
        }
        res.push_back(nums[lastIndex]);
        reverse(res.begin(),res.end());

        return res;
    }
};