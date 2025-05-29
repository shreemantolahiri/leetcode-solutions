// Time Complexity: O(n^2) - checking all pairs
// Space Complexity: O(1) - no extra space used except output

class Solution {
    public int[] twoSum(int[] nums, int target) {
        // Brute-force: check all pairs
        for (int i = 0; i < nums.length; i++) {
            for (int j = i + 1; j < nums.length; j++) {
                if (nums[i] + nums[j] == target) {
                    return new int[]{i, j}; // Found the pair
                }
            }
        }

        return new int[]{}; // No valid pair found
    }
}
