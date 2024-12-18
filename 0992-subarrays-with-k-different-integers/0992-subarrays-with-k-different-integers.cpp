class Solution {
public:
    int solve(vector<int>& nums, int k){
        if(k<0) return 0;
        int left=0,right=0;
        unordered_map<int,int> mp;
        int n=nums.size();
        int sum=0;

        int count=0;
        for(;right<n;right++){
            mp[nums[right]]++;
            // cout<<left<< " "<<right<<endl;
            while(mp.size()>k && left<=right){
                mp[nums[left]]--;

                if(mp[nums[left]]==0) mp.erase(nums[left]);
                left++;
            }

            count+=right-left+1;
        }

        return count;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return solve(nums,k) - solve(nums,k-1);
    }
};