class Solution {
public:
    string reverseParentheses(string s) {
        stack<char> st;
        queue<char> temp;

        for(int i=0;i<s.length();i++){
            if(s[i]==')'){
                while(!st.empty() && st.top()!='('){
                    temp.push(st.top());
                    st.pop();
                }
                if(!st.empty()) st.pop();

                while(!temp.empty()){
                    st.push(temp.front());
                    temp.pop();
                }
            }
            else{
                st.push(s[i]);
            }
        }

        string res="";
        while(!st.empty()){
            res+=st.top();
            st.pop();
        }
        reverse(res.begin(),res.end());
        return res;
    }
};