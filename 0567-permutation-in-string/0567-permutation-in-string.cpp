class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.length() > s2.length()) return false;
        
        vector<int> s1_count(26, 0);
        vector<int> window_count(26, 0);
        
        // Count the frequencies of characters in s1
        for (char c : s1) {
            s1_count[c - 'a']++;
        }
        
        // Initialize the window
        for (int i = 0; i < s1.length(); i++) {
            window_count[s2[i] - 'a']++;
        }
        
        if (s1_count == window_count) return true;
        
        // Slide the window
        for (int i = s1.length(); i < s2.length(); i++) {
            window_count[s2[i - s1.length()] - 'a']--;
            window_count[s2[i] - 'a']++;
            
            if (s1_count == window_count) return true;
        }
        
        return false;
    }
};