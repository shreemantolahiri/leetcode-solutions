class Solution {
public:
    int isVowel(char ch) {

        switch (ch) {
        case 'a':
            return 0;
        case 'e':
            return 1;
        case 'i':
            return 2;
        case 'o':
            return 3;
        case 'u':
            return 4;

        default:
            return -1;
        }

        return -1;
    }
    int findTheLongestSubstring(string s) {
        vector<int> count(5, 0); // a e i o u

        int n = s.length();
        unordered_map<string, int> mp;
        mp["00000"] = -1;
        int longest = 0;
        for (int i = 0; i < n; i++) {
            int code = isVowel(s[i]);

            if (code != -1)
                count[code] = (count[code] + 1) % 2;

            string freq = "";
            
            for (int j = 0; j < 5; j++) {
                freq += to_string(count[j]);
            }
            if (mp.find(freq) != mp.end()) {
                longest = max(longest, i - mp[freq]);
            }
            else{
                mp[freq]=i;
            }
        }

        return longest;
    }
};