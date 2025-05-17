// Time Complexity: O(n) — where n is the length of the strings
// Space Complexity: O(1) — fixed-size array for 26 lowercase letters

class Solution {
    public boolean isAnagram(String s, String t) {
        int n = s.length(), m = t.length();
        if (n != m) return false; // Lengths don't match → can't be anagrams

        HashMap<Character,Integer> freq=new HashMap<>();

        // Count characters in s
        for (char c : s.toCharArray()) {
            freq.put(c, freq.getOrDefault(c,0)+1);
        }

        // Subtract characters in t
        for (char c : t.toCharArray()) {
            if (!freq.containsKey(c) || freq.get(c) == 0) return false;
            freq.put(c, freq.getOrDefault(c,0)-1);
        }

        return true; // All characters matched
    }
}
