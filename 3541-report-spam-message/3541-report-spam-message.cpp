class Solution {
public:
    bool reportSpam(vector<string>& message, vector<string>& bannedWords) {
        unordered_set<string> st(bannedWords.begin(), bannedWords.end());
        // for(string &s: bannedWords) st.insert(s);


        int count=0;
        for(string &s:message){
            if(st.find(s)!=st.end()) count++;
            if(count==2) return true;
        }

        return false;
    }
};