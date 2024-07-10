class Solution {
public:
    int compareVersion(string version1, string version2) {
        int n = version1.size(); // Get the length of version1
        int m = version2.size(); // Get the length of version2
        
        int i = 0, j = 0; // Initialize indices to traverse version1 and version2

        // Loop until we have traversed both version strings
        while (i < n || j < m) {
            long long num1 = 0, num2 = 0; // Variables to store the current number segments
            
            // Parse number from version1
            while (i < n && version1[i] != '.') { // Continue until we find a dot or reach the end
                num1 = num1 * 10 + (version1[i] - '0'); // Build the number segment
                i++; // Move to the next character
            }
            // Skip the dot
            i++; // Move past the dot for the next segment
            
            // Parse number from version2
            while (j < m && version2[j] != '.') { // Continue until we find a dot or reach the end
                num2 = num2 * 10 + (version2[j] - '0'); // Build the number segment
                j++; // Move to the next character
            }
            // Skip the dot
            j++; // Move past the dot for the next segment
            
            // Compare the parsed numbers
            if (num1 > num2) return 1; // If version1's segment is greater, return 1
            if (num1 < num2) return -1; // If version2's segment is greater, return -1
        }

        // If all segments are equal, return 0
        return 0;
    }
};
