class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s2.length();
        int m = s1.length();
        vector<int> mp(26,0);
        for (char ch : s1)
            mp[ch-'a']++;

         vector<int> mp1(26,0);

        int i = 0, j = 0;

        while (j < n) {
            // if (j - i == m)
            //     return true;
            char ch = s2[j];
            if (mp[ch-'a'] == 0) {
                // does not exist
                fill(mp1.begin(), mp1.end(), 0);
                i = j + 1;
                j++;
            } else if (mp1[ch-'a'] < mp[ch-'a']) {
                mp1[ch-'a']++;
                j++;
            } else {
                mp1[ch-'a']++;
                while (i < j && mp1[ch-'a'] > mp[ch-'a']) {
                    mp1[s2[i]-'a']--;
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