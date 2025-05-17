class Solution {
    public boolean isAnagram(String s, String t) {
        //brute force
        int n=s.length(); int m=t.length();
        if(n!=m) return false;
        int[] freq = new int[26]; // Automatically initialized to 0
        for(Character c: s.toCharArray()){
            freq[c-'a']++;
        }
        for(Character c: t.toCharArray()){
            if(freq[c-'a']==0) return false;
            else freq[c-'a']--;
        }
        return true;
    }
}