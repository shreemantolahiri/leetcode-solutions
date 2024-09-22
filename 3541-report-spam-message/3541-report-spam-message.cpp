class Solution {
public:
    bool reportSpam(vector<string>& message, vector<string>& bannedWords) {
        unordered_set<string> st(bannedWords.begin(), bannedWords.end());
        


        int count=0;
        for(string &s:message){
            if(st.count(s)>0) count++;
            if(count==2) return true;
        }

        return false;
    }
};