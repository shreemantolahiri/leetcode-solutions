class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        vector<bool> ans;
        int res=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            res=res*2+nums[i];
            if(res%5==0) ans.push_back(true);
            else ans.push_back(false);
            
            res=res%5;
        }
        
        return ans;
    }
};