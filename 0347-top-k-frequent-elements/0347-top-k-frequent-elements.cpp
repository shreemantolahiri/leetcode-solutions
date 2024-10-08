class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        //making map
        for(auto &it: nums){
            mp[it]++;
        }

        int n=nums.size();
        vector<vector<int>> bucket(n+1);
        for(auto &it:mp){
            int freq=it.second;
            int ele=it.first;

            bucket[freq].push_back(ele);
        }


        vector<int> res;
        for(int i=n;i>=0;i--){
            if(res.size()==k) break;
            res.insert(res.end(),bucket[i].begin(),bucket[i].end());
        }
        return res;
    }
};