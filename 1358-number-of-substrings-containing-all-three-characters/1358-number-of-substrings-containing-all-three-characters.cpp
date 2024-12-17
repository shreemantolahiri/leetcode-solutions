class Solution {
public:
    int numberOfSubstrings(string s) {
        int a=-1,b=-1,c=-1;
        int count=0;
        for(int i=0;i<s.length();i++){
            if(s[i]=='a') a=i;
            else if(s[i]=='b') b=i;
            else c=i;

            int startOfWindow=min({a,b,c});
            if(startOfWindow!=-1) count+=startOfWindow+1;
        }

        return count;
    }
};