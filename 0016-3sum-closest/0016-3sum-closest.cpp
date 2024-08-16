class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n = nums.size();

        int closest = nums[0] + nums[1] + nums[2];
        int diff = abs(target - closest);
        for (int i = 0; i < n - 2; i++) {
            int j = i + 1;
            int k = n - 1;
            int curr = nums[i];
            while (j < k && i<k) {
                int newcurr = curr + nums[j] + nums[k];
                int newdiff = abs(newcurr - target);

                if (newdiff < diff) {
                    diff = newdiff;
                    closest = newcurr;
                }
                if (target > newcurr) {
                    j++;
                    continue;
                } else {
                    k--;
                    continue;
                }
            }
        }

        return closest;
    }
};