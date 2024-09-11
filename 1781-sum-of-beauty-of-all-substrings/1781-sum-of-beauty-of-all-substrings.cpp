class Solution {
public:
    int beautySum(string s) {
        int count = 0;
        int n = s.length();
        // traverse over all substrings
        for (int i = 0; i < n; i++) {
            vector<int> mp(26, 0);
            for (int j = i; j < n; j++) {
                char ch = s[j];
                int ind = ch - 'a';
                mp[ind]++;

                // find max and least
                int maxTimes = INT_MIN;
                int minTimes = INT_MAX;
                for (auto it : mp) {
                    if(it!=0) maxTimes = max(maxTimes, it);
                    if(it!=0) minTimes = min(minTimes, it);
                }

                if (maxTimes != INT_MIN && minTimes != INT_MAX) {
                    count += maxTimes - minTimes;
                }
            }
        }

        return count;
    }
};