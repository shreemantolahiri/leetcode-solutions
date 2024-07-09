class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length()!=t.length()) return false;
        unordered_map<char,int> mp;

        for(char &c:s){
            mp[c]++;
        }

        for(char &c:t){
            if(mp[c]==0) return false;
            else mp[c]--;
        }

        return true;
    }
};