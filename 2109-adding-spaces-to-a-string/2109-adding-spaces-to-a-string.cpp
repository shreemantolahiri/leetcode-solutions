class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        
        string res="";

        int j=0;
        for(int i=0;i<s.length();i++){
            if(j>=spaces.size()){
                res+=s[i];
                continue;
            }
            if(spaces[j]==i){
                res+=' ';
                // res+=s[i];
                j++;
                // continue;
            }
            //add the alphabet
            res+=s[i];
        }

        return res;
    }
};