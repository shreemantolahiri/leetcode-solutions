// Time Complexity: O(n) — where n is the length of the strings
// Space Complexity: O(1) — fixed-size array for 26 lowercase letters

class Solution {
    public boolean isAnagram(String s, String t) {
        int n = s.length(), m = t.length();
        if (n != m) return false; // Lengths don't match → can't be anagrams

        int[] freq = new int[26]; // Frequency array for lowercase English letters

        // Count characters in s
        for (char c : s.toCharArray()) {
            freq[c - 'a']++;
        }

        // Subtract characters in t
        for (char c : t.toCharArray()) {
            if (freq[c - 'a'] == 0) return false; // t has extra character
            freq[c - 'a']--;
        }

        return true; // All characters matched
    }
}
