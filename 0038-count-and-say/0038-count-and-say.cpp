class Solution {
public:
    string solve(int n){
        if(n==1) return "1";

        string s=solve(n-1);

        //process s

        string str="";
        int count=1;
        for(int i=1;i<s.length();i++){
            if(s[i-1]==s[i]){
                count++;
            }
            else{
                str+=to_string(count);
                str+=s[i-1];
                count=1;
            }
        }
        str+=to_string(count);
        str+=s[s.size()-1];

        return str;
        
    }
    string countAndSay(int n) {
        return solve(n);
    }
};