class Solution {
public:
    unordered_map<string, bool> memo;

    // Helper function to convert groups vector to a string for memoization
    string hashGroups(const vector<int>& groups) {
        string key = "";
        for (int group : groups) {
            key += to_string(group) + ",";
        }
        return key;
    }

    bool solve(int ind, vector<int>& nums, vector<int>& groups, int target) {
        // Base case: If all elements have been assigned
        if (ind == nums.size()) {
            return true; // If we've placed all elements, the partition is valid
        }

        // Hash the current state (groups) and check if it's already computed
        string hashKey = hashGroups(groups);
        if (memo.find(hashKey) != memo.end()) return memo[hashKey];

        // Try placing the current number in each group
        for (int i = 0; i < groups.size(); i++) {
            // Pruning: Skip if adding nums[ind] would exceed the group sum
            if (groups[i] + nums[ind] > target) continue;
            
            // Pruning: Avoid redundant states (skip empty groups unless it's the first one)
            if (i > 0 && groups[i] == groups[i-1]) continue;

            groups[i] += nums[ind];
            if (solve(ind + 1, nums, groups, target)) {
                return memo[hashKey] = true; // Memoize the result before returning
            }
            groups[i] -= nums[ind]; // Backtrack
        }

        return memo[hashKey] = false; // Memoize the failed result
    }

    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int totalSum = accumulate(nums.begin(), nums.end(), 0);

        // If the total sum isn't divisible by k, we can't partition
        if (totalSum % k != 0) return false;
        int target = totalSum / k;

        // Sort in descending order for better performance
        sort(nums.begin(), nums.end(), greater<int>());

        // If any number is greater than the target, it's impossible to partition
        if (nums[0] > target) return false;

        vector<int> groups(k, 0);
        memo.clear();

        // Start the recursive partitioning process
        return solve(0, nums, groups, target);
    }
};
