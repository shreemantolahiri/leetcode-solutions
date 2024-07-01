class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int low = 0;
        int high = arr.size() - 1;
        cout<<low<<" "<<high<<endl;
        // Perform binary search
        while (low <= high) {
            cout<<low<<" "<<high<<endl;
            int mid = low + (high - low) / 2;

            // Calculate the number of missing elements up to arr[mid]
            int missing = arr[mid] - (mid + 1);

            if (missing < k) {
                // If missing elements are less than k, search in the right half
                low = mid + 1;
            } else {
                // If missing elements are greater than or equal to k, search in the left half
                high = mid - 1;
            }
        }
        if (high == -1) {
            return k;
        }
        cout<<low<<" "<<high<<endl;
        // After exiting the loop, low is the index where the k-th missing number would be inserted
        // Calculate how many more elements are needed after arr[high]
        int moreDiff = k - (arr[high] - (high + 1));

        // The k-th missing positive number
        return arr[high] + moreDiff;
    }
};
