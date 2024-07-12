class Solution {
public:
    int maximumGain(string s, int x, int y) {
        int score = 0;
        if (x > y) {
            // ab > ba
            stack<char> st;
            for (int i = 0; i < s.length(); i++) {
                if (s[i] == 'b') {
                    if (!st.empty() && st.top() == 'a') {
                        score += x;
                        st.pop();
                    } else {
                        st.push('b');
                    }
                } else {
                    st.push(s[i]);
                }
            }

            // we unstack everything and check for patterns
            string remaining;
            while (!st.empty()) {
                remaining += st.top();
                st.pop();
            }
            reverse(remaining.begin(), remaining.end());
            
            for (int i = 0; i < remaining.length(); i++) {
                if (remaining[i] == 'a') {
                    if (!st.empty() && st.top() == 'b') {
                        score += y;
                        st.pop();
                    } else {
                        st.push('a');
                    }
                } else {
                    st.push(remaining[i]);
                }
            }
        } else {
            // ba > ab
            stack<char> st;
            for (int i = 0; i < s.length(); i++) {
                if (s[i] == 'a') {
                    if (!st.empty() && st.top() == 'b') {
                        score += y;
                        st.pop();
                    } else {
                        st.push('a');
                    }
                } else {
                    st.push(s[i]);
                }
            }

            // we unstack everything and check for patterns
            string remaining;
            while (!st.empty()) {
                remaining += st.top();
                st.pop();
            }
            reverse(remaining.begin(), remaining.end());

            for (int i = 0; i < remaining.length(); i++) {
                if (remaining[i] == 'b') {
                    if (!st.empty() && st.top() == 'a') {
                        score += x;
                        st.pop();
                    } else {
                        st.push('b');
                    }
                } else {
                    st.push(remaining[i]);
                }
            }
        }

        return score;
    }
};