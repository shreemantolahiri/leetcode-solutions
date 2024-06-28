class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int left = 0;
        int right = n - 1;
        int mini = INT_MAX;
        
        // Perform binary search
        while (left <= right) {
            int mid = left + (right - left) / 2;
            
            // If duplicates are encountered
            if (nums[left] == nums[mid] && nums[mid] == nums[right]) {
                mini = min(nums[mid], mini);
                left++;
                right--;
            }
            // If the left half is sorted
            else if (nums[left] <= nums[mid]) {
                mini = min(nums[left], mini);
                left = mid + 1;
            }
            // If the right half is sorted
            else {
                mini = min(nums[mid], mini);
                right = mid - 1;
            }
        }
        
        return mini;
    }
};