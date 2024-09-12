class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        if (prices.empty()) return 0;

        long long ans = 1;
        int last = 1;
        
        for (int i = 1; i < prices.size(); i++) {
            if (prices[i - 1] - prices[i] == 1) {
                last++;
            } else {
                last = 1;
            }
            ans += last;
        }

        return ans;
    }
};
