class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> mp;

        int sum=0;
        mp[sum]=1;
        int count=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];

            //check if sum-(prefix array)==k

            count+=mp[sum-k];
            mp[sum]++;
        }

        return count;
    }
};