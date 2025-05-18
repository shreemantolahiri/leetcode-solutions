// Time Complexity: O(n) — where n is the length of the strings
// Space Complexity: O(n) — for storing frequency map (worst case all unique characters)

import java.util.HashMap;

class Solution {
    public boolean isAnagram(String s, String t) {
        int n = s.length(), m = t.length();
        if (n != m) return false; // Strings of different lengths cannot be anagrams

        HashMap<Character, Integer> freq = new HashMap<>();

        // Count characters in s
        for (char c : s.toCharArray()) {
            freq.put(c, freq.getOrDefault(c, 0) + 1);
        }

        // Subtract character frequencies using t
        for (char c : t.toCharArray()) {
            if (!freq.containsKey(c) || freq.get(c) == 0) return false; // Extra or unmatched character
            freq.put(c, freq.get(c) - 1);
        }

        return true; // All character frequencies matched
    }
}
