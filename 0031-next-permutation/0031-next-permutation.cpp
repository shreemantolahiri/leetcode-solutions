class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size(); // Get the size of the array
        int i = n - 2; // Initialize i to the second last index

        // Find the first pair of two successive numbers a[i] and a[i+1], from the end, which satisfy a[i] < a[i+1]
        for (i = n - 2; i >= 0; i--) {
            if (nums[i + 1] <= nums[i]) 
                continue; // If nums[i+1] is not greater than nums[i], continue searching
            else 
                break; // If we find nums[i] < nums[i+1], break the loop
        }

        // If no such pair is found, it means the array is sorted in descending order
        if (i == -1) {
            // Reverse the entire array to get the smallest permutation
            // O(N)
            reverse(nums.begin(), nums.end());
        } else {
            // We break at index i
            cout << nums[i] << endl; // Output the value at index i for debugging

            // Find the smallest number greater than nums[i] to the right of nums[i]
            int j = i + 1;
            for (int k = i + 1; k < n; k++) {
                if (nums[k] > nums[i] && nums[k] <= nums[j]) {
                    j = k;
                }
            }

            // Swap the number at i with this number
            swap(nums[i], nums[j]);

            // Reverse the numbers following i to get the next permutation
            reverse(nums.begin() + i + 1, nums.end());
        }
    }
};
