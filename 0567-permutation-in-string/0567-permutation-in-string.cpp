class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s2.length();
        unordered_map<char, int> mp;
        for (char ch : s1)
            mp[ch]++;

        unordered_map<char, int> backup = mp;
        int j = 0;
        for (int i = 0; i < n; i++) {
            char ch = s2[i];

            if (mp.find(ch) != mp.end()) {
                // in map
                mp[ch]--;
                if (mp[ch] == 0)
                    mp.erase(ch);
                if (mp.size() == 0)
                    return true;
                int j = i + 1;
                while (j < n) {
                    if (mp.find(s2[j]) == mp.end())
                        break;

                    else {
                        mp[s2[j]]--;
                        if (mp[s2[j]] == 0)
                            mp.erase(s2[j]);
                    }
                    j++;
                }
                if (mp.size() == 0)
                    return true;
                else
                    mp = backup;
            } else {
                // not existing in map
                //  mp=backup;
                continue;
            }
        }

        return false;
    }
};