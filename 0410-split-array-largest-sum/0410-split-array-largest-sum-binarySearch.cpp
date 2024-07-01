class Solution {
public:
    // Function to check if the array can be split into `k` subarrays with the maximum sum `maxSum`
    bool canBeSplit(vector<int>& nums, int k, long long maxSum) {
        int currSum = nums[0]; // Initialize current subarray sum with the first element
        int painters = 1; // Initialize the number of subarrays (painters) with 1

        // Iterate through the array starting from the second element
        for (int i = 1; i < nums.size(); i++) {
            // If the number of subarrays exceeds `k`, break the loop
            if (k < painters) break;

            // Check if adding the current element to the current subarray sum exceeds `maxSum`
            if (currSum + nums[i] <= maxSum) {
                currSum += nums[i]; // Add the current element to the current subarray sum
            } else {
                // If it exceeds, start a new subarray
                painters++; // Increment the number of subarrays
                currSum = nums[i]; // Start the new subarray with the current element
            }
        }

        // Return true if the number of subarrays is less than or equal to `k`, otherwise false
        return painters <= k;
    }

    // Function to find the minimum possible largest sum among `k` subarrays
    int splitArray(vector<int>& nums, int k) {
        int left = INT_MIN; // Initialize the lower bound for binary search (max element in `nums`)
        long long right = 0; // Initialize the upper bound for binary search (sum of all elements in `nums`)

        // Find the initial values for `left` and `right`
        for (int i = 0; i < nums.size(); i++) {
            left = max(left, nums[i]); // The largest element in `nums` (lower bound)
            right += nums[i]; // The sum of all elements in `nums` (upper bound)
        }

        // Binary search to find the minimum possible largest sum
        while (left <= right) {
            long long mid = left + (right - left) / 2; // Calculate the middle value

            // Check if the array can be split into `k` subarrays with the maximum sum `mid`
            if (canBeSplit(nums, k, mid)) {
                right = mid - 1; // If possible, search in the lower half
            } else {
                left = mid + 1; // If not possible, search in the upper half
            }
        }

        // Return the minimum possible largest sum
        return left;
    }
};
