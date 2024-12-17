class Solution {
public:
    bool allPresent(vector<int> &count){
        return (count[0] && count[1] && count[2]);
    }
    int numberOfSubstrings(string s) {
        int n=s.length();

        int left=0,right=0;
        vector<int> count(3,0);
        int res=0;
        while(right<n){
            count[s[right]-97]++;

            while(allPresent(count)){
                res+=n-right;
                count[s[left]-97]--;
                left++;
            }
            right++;
        }

        return res;
    }
};