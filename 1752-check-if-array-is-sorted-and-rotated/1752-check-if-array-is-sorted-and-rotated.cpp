class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size();
        // first case
        if (nums[0] < nums[n - 1]) {
            // check in a for loop
            for (int i = 1; i < n; i++) {
                if (nums[i] < nums[i - 1])
                    return false;
            }

            return true;
        } else {
            // search for smallest num

            int ind = 0;

            for (int i = 1; i < n; i++) {
                if (nums[i] < nums[ind])
                    ind = i;
            }

            // find first occurrence
            int firstInd = ind;

            for (int i = 1; i < n; i++) {
                if (nums[i] == nums[ind] && nums[i - 1] > nums[i])
                    firstInd = i;
            }

            //we got the first number of series

            for(int i=firstInd+1;i<n;i++){
                if(nums[i-1]>nums[i]) return false;
            }

            for(int i=1;i<firstInd;i++){
                if(nums[i-1]>nums[i]) return false;
            }

            return true;


        }
    }
};