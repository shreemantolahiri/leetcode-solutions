class Solution {
public:
    #define ll long long
    #define MOD 1000000007
    
    // Function to calculate the hash value of a string `s` using the given `RADIX` and length `m`
    ll hash(string &s, ll RADIX, ll m) {
        ll ans = 0;  // Initialize hash value
        ll factor = 1;  // Initialize factor to compute the positional weight
        
        // Calculate hash from the last character to the first character
        for (ll i = m - 1; i >= 0; i--) {
            ans = (ans + ((s[i] - 'a') * factor) % MOD) % MOD;  // Update hash value with the current character's weighted value
            factor = (factor * RADIX) % MOD;  // Update factor to the next positional weight
        }

        return ans % MOD;  // Return the final hash value
    }

    // Function to find the first occurrence of the needle in the haystack
    int strStr(string haystack, string needle) {
        int n = haystack.length();  // Length of the haystack
        int m = needle.length();  // Length of the needle
        if (m > n) return -1;  // If the needle is longer than the haystack, return -1

        ll RADIX = 26;  // Radix (base) used for hashing
        ll MAX_WEIGHT = 1;  // Maximum weight factor (26^m) for the rolling hash
        
        // Compute MAX_WEIGHT = 26^m % MOD
        for (ll i = 1; i <= m; i++) {
            MAX_WEIGHT = (MAX_WEIGHT * RADIX) % MOD;
        }

        // Compute the hash value for the needle
        ll hashNeedle = hash(needle, RADIX, m);
        ll hashHay = 0;  // Initialize the hash value for the current window in the haystack

        // Iterate through the haystack to find the needle
        for (ll i = 0; i <= n - m; i++) {
            if (i == 0) {
                // Compute the hash value for the first window of length `m` in the haystack
                hashHay = hash(haystack, RADIX, m);
            } else {
                // Compute the rolling hash for the next window by removing the leftmost character and adding the new character
                hashHay = ((hashHay * RADIX) % MOD - (((haystack[i - 1] - 'a') * MAX_WEIGHT) % MOD) + (haystack[i + m - 1] - 'a') + MOD) % MOD;
            }

            // If the hash values match, do a character-by-character comparison to confirm
            if (hashNeedle == hashHay) {
                for (ll j = 0; j < m; j++) {
                    if (needle[j] != haystack[j + i]) break;  // Break if characters do not match
                    if (j == m - 1) return i;  // If all characters match, return the starting index
                }
            }
        }

        return -1;  // If no match is found, return -1
    }
};
