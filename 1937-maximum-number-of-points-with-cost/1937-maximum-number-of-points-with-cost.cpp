class Solution {
public:
    long long maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        int m = points[0].size();

        vector<long long> prev(m, 0);
        vector<long long> curr(m, 0);

        for (int i = 0; i < m; i++) {
            prev[i] = points[0][i];
        }

        if (n == 1) return *max_element(prev.begin(), prev.end());

        for (int i = 1; i < n; i++) {
            vector<long long> left(m, 0);
            vector<long long> right(m, 0);

            // Fill the left array
            left[0] = prev[0];
            for (int k = 1; k < m; k++) {
                left[k] = max(prev[k], left[k - 1] - 1);
            }

            // Fill the right array
            right[m - 1] = prev[m - 1];
            for (int k = m - 2; k >= 0; k--) {
                right[k] = max(prev[k], right[k + 1] - 1);
            }

            // Calculate the current row's maximum points
            for (int k = 0; k < m; k++) {
                curr[k] = points[i][k] + max(left[k], right[k]);
            }

            prev = curr;
        }

        return *max_element(prev.begin(), prev.end());
    }
};