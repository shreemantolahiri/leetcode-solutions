class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        // Sort the array and use 3 pointers
        // TC: O(nlogn + n) = O(nlogn), SC: O(logn)
        const int n = nums.size();
        sort(nums.begin(), nums.end());

        int64_t pairs = 0;
        for (int l = 0, r = n - 1, mid = r - 1; l < r; ) {
            const int sum = nums[l] + nums[r];

            if (upper < sum) {
                // Decrease the sum by getting a lower number
                r -= 1;
                if (r == mid) mid -= 1;
            } else if (sum < lower) {
                // Increase the sum by getting a higher number
                l += 1;
                if (mid < l) mid += 1;
            } else {
                // Find the lowest index that can be paired with nums[l] such that lower <= nums[l] + nums[mid + 1]
                while (l < mid && lower <= nums[l] + nums[mid]) {
                    mid -= 1;
                }

                // Count all the numbers that can be paired with nums[l] to make their sum within the range [lower, upper]
                pairs += r - mid;
                l += 1;
                if (mid < l) mid += 1;
            }
        }

        return pairs;

        /* -------------------------------------------------- */

        /*
        // Brute Force
        // TC: O(n^2), SC: O(1)
        const int n = nums.size();

        int64_t fPairs = 0;
        for (int i = 0; i < n - 1; ++i) {
            for (int j = i + 1; j < n; ++j) {
                const int sum = nums[i] + nums[j];
                if (lower <= sum && sum <= upper)
                    fPairs += 1;
            }
        }

        return fPairs;
        */
    }
};

static const char a = [](){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    return 0;
}();