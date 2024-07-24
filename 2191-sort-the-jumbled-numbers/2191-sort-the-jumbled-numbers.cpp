class Solution {
public:
    // This function maps the digits of a number 'a' using the provided 'mapping' array
    int mappedNumber(int a, vector<int>& mapping) {
        // Convert the integer 'a' to a string to handle each digit individually
        string s = to_string(a);
        int num = 0; // This will store the newly mapped number
        
        // Loop through each character in the string representation of the number
        for (int i = 0; i < s.length(); i++) {
            int curr = s[i] - '0';  // Convert the character to an integer digit
            int map = mapping[curr];  // Get the mapped value for the current digit
            num = num * 10 + map;  // Construct the new number using the mapped digits
        }

        return num;  // Return the mapped number
    }

    // This function sorts the 'nums' array based on the mapped values of the numbers
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        unordered_map<int,int> mp;

        for(int i=0;i<nums.size();i++){
            mp[nums[i]]=mappedNumber(nums[i],mapping);
        }
        
        // Use the sort function with a custom comparator lambda function
        
        sort(nums.begin(), nums.end(), [&](int a, int b) {
            // Get the mapped values for both numbers a and b
            int mappeda = mp[a];
            int mappedb = mp[b];

            // If the mapped values are equal, maintain their original order
            if (mappeda == mappedb) {
                return false;  // Since they are equal, return false (no need to swap)
            } else {
                // Otherwise, sort based on the mapped values
                return mappeda < mappedb;  // Sort in ascending order of mapped values
            }
        });

        return nums;  // Return the sorted array
    }
};
auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();