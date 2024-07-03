class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n=nums.size();

        unordered_map<int,int> mp;
        mp[0]=1;
        int s=0;
        int res=0;
        for(auto it:nums){
            s+=it;
            
            if(s>=goal){
                if(mp.find(s-goal)!=mp.end()){
                    res+=mp[s-goal];
                }
            }

            mp[s]++;
        }
        
        // for(auto it:mp){
            
        //     int sum=it.first;
        //     if(sum<goal) continue;
        //     else{
        //         if(mp.find(sum-goal)!=mp.end()){
        //             res+=mp[sum-goal];
        //         }
        //     }
        // }

        return res;
    }
};