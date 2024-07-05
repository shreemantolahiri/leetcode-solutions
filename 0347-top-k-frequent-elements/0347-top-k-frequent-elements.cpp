class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        //making map
        for(auto &it: nums){
            mp[it]++;
        }

        int n=nums.size();
        
        //min heap
        priority_queue< pair<int,int>,
        vector<pair<int,int>>,
        greater<pair<int,int>> > pq;

        for(auto &it:mp){
            //check if heap is full then remove smallest element
            if(pq.size()<k) pq.push({it.second,it.first});
            else if(pq.size()==k && pq.top().first<it.second){
                pq.pop();
                pq.push({it.second,it.first});
            }

            // pq.push({it.second,it.first});
        }

        vector<int> res;
        while(!pq.empty()){
            res.push_back(pq.top().second);
            pq.pop();
        }

        return res;
    }
};