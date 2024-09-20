class Solution {
public:
    string reverseWords(string s) {
        int n=s.length();

        string res="";
        string temp="";
        for(int i=n-1;i>=0;i--){
            if(s[i]==' '){
                if(temp.size()==0) continue;
                reverse(temp.begin(),temp.end());
                res+=temp;
                res+=' ';
                temp.clear();
            }
            else{
                temp+=s[i];
            }
        }

        if(temp.size()>0){
            reverse(temp.begin(),temp.end());
            res+=temp;
        }
        //remove extra spaces
        while(res.length()>0){
            if(res[res.length()-1]==' ') res.pop_back();
            else break;
        }
        return res;
    }
};