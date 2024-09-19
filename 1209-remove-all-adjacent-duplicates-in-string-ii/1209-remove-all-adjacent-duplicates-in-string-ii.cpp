class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<char, int>> st;

        for (int i = 0; i < s.length(); i++) {
            // check if last char is same
            if (!st.empty()) {
                if (st.top().first == s[i]) {
                    // if last count==k-1 then pop
                    if (st.top().second == k - 1) {
                        while (!st.empty() && st.top().first == s[i])
                            st.pop();
                        continue;
                    } else {
                        // add one and push
                        int prevNumber = st.top().second;
                        st.push({s[i], prevNumber + 1});
                    }
                } else {
                    // first char
                    st.push({s[i], 1});
                }
            } else {
                // first char
                st.push({s[i], 1});
            }
        }

        string res = "";
        while (!st.empty()) {
            res += st.top().first;
            st.pop();
        }

        reverse(res.begin(), res.end());

        return res;
    }
};