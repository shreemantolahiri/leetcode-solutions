class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s2.length();
        int m = s1.length();
        unordered_map<char, int> mp;
        for (char ch : s1)
            mp[ch]++;

        unordered_map<char, int> mp1;

        int i = 0, j = 0;

        while (j < n) {
            // if (j - i == m)
            //     return true;
            char ch = s2[j];
            if (mp[ch] == 0) {
                // does not exist
                mp1.clear();
                i = j + 1;
                j++;
            } else if (mp1[ch] < mp[ch]) {
                mp1[ch]++;
                j++;
            } else {
                mp1[ch]++;
                while (i < j && mp1[ch] > mp[ch]) {
                    mp1[s2[i]]--;
                    i++;
                }
                j++;
            }

            if (j - i == m)
                return true;
        }

        return false;
    }
};