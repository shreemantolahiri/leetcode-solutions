class Solution {
public:
    int bitwiseComplement(int num) {
        string s="";
        if(num==0) return 1;
        while(num>0){
            if(num%2==0){
                s+='0';
            }
            else s+='1';

            num/=2;
        }

        // reverse(s.begin(),s.end());
        int n=0;
        long long pow=1;

        for(int i=0;i<s.length();i++){
            if(s[i]=='0'){
                n+=pow;
            }

            pow=pow*2;
        }

        return n;

    }
};