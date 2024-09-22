class Solution {
public:
    bool reportSpam(const vector<string>& message, const vector<string>& bannedWords) {
        // Initialize an unordered_set with banned words for O(1) lookups
        unordered_set<string> st(bannedWords.begin(), bannedWords.end());

        int count = 0;

        // Iterate over the message vector and check for banned words
        for (const string &s : message) {
            // Check if the current word is in the banned words set
            if (st.count(s)) {
                count++;
                // Return true if two banned words are found
                if (count == 2) return true;
            }
        }

        // Return false if fewer than 2 banned words are found
        return false;
    }
};
