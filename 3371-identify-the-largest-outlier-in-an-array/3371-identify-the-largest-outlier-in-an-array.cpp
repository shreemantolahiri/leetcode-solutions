class Solution {
public:
    int getLargestOutlier(vector<int>& nums) {
       int total_sum=0;
        int n=nums.size();
        unordered_map<int,int> mp;
        for(int i=0;i<n;i++){
            total_sum+=nums[i];
            mp[nums[i]]++;
        }
        int ans=INT_MIN;
        //now we treat every number if its sum
        for(int i=0;i<n;i++){
            int sum=nums[i];
            
            int out=total_sum-2*sum;
            
            if(sum!=out && mp.find(out)!=mp.end()){
                ans=max(ans,out);
            }
            if(sum==out && mp[out]>1){
                ans=max(ans,out);
            }
            
        }
        
        return ans;
    }
};