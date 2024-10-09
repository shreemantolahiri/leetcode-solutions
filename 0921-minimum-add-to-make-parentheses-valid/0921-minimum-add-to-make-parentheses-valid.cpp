class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char> st;

        int count=0;
        for(int i=0;i<s.length();i++){
            if(s[i]=='(') st.push(s[i]);
            else{
                if(!st.empty()) st.pop();
                else{
                    //assume we push a '(' to match it
                    count++;
                }
            }
        }

        count+=st.size();

        return count;
    }
};