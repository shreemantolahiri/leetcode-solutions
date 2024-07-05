class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        // Step 1: Count frequencies of each element
        for (auto &it : nums) {
            mp[it]++;
        }

        int n = nums.size();
        vector<vector<int>> bucket(n + 1);
        // Step 2: Place elements into buckets based on their frequency
        for (auto &it : mp) {
            int freq = it.second;
            int ele = it.first;
            bucket[freq].push_back(ele);
        }

        vector<int> res;
        res.reserve(k);  // Reserve space for k elements in the result vector
        // Step 3: Collect the top k frequent elements from the buckets
        for (int i = n; i >= 0; i--) {
            if (res.size() == k) break;  // If we have collected k elements, stop
            res.insert(res.end(), bucket[i].begin(), bucket[i].end());
        }

        res.resize(k);  // Ensure the result vector has exactly k elements

        return res;
    }
};
