class Solution {
public:
    bool doesAliceWin(string s) {
        int vowels=0;
        int n=s.length();
        for(int i=0;i<n;i++){
            if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u'){
                vowels++;
            }
        }
        
        //if vowels are odd remove all
        if(vowels%2!=0) return true;
        else if(vowels==0) return false;
        else return true;
    }
};