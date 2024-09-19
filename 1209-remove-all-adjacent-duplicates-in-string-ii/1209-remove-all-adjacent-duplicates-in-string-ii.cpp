class Solution {
public:
    string removeDuplicates(string s, int k) {
        vector<int> count(s.size(),0);
        int i = 0,j=0;
        while(j<s.size())
        {
            s[i] = s[j];
            count[i] = 1;
            if(i>0 and s[i]==s[i-1])
            {
                count[i] += count[i-1];
            }
            if(count[i]==k)
            {
                i -= k;
            }
            i++,j++;
        }
        string ans = s.substr(0,i);
        return ans;
    }
};