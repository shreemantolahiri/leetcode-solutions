class Solution {
public:
    int partitionString(string s) {
        unordered_set<char> st;
        int count=0;
        for(int i=0;i<s.length();i++){
            char ch=s[i];

            if(st.count(ch)){
                count++;
                st.clear();
                st.insert(ch);
            }
            else{
                st.insert(ch);
            }
        }

        return count+1;
    }
};