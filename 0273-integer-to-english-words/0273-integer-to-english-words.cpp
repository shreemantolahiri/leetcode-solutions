class Solution {
public:
    unordered_map<int, string> belowTen = { {0, ""}, {1, "One"}, {2, "Two"}, {3, "Three"}, {4, "Four"}, {5, "Five"}, {6, "Six"}, {7, "Seven"}, {8, "Eight"}, {9, "Nine"} };
    unordered_map<int, string> belowTwenty = { {10, "Ten"}, {11, "Eleven"}, {12, "Twelve"}, {13, "Thirteen"}, {14, "Fourteen"}, {15, "Fifteen"}, {16, "Sixteen"}, {17, "Seventeen"}, {18, "Eighteen"}, {19, "Nineteen"} };
    unordered_map<int, string> belowHundred = { {1, "Ten"}, {2, "Twenty"}, {3, "Thirty"}, {4, "Forty"}, {5, "Fifty"}, {6, "Sixty"}, {7, "Seventy"}, {8, "Eighty"}, {9, "Ninety"} };

    string solve(int num, int pos){
        if(num<=0) return "";

        int n=num%1000;
        int prev=n;
        string s="";
        int ones=n%10;
        n/=10;
        int tens=n%10;
        n/=10;
        int hundreds=n%10;
        int twnty=tens*10+ones;
        if(hundreds>0)s+=" "+belowTen[hundreds]+" Hundred";
        if(twnty>=11 && twnty<20) s+=" "+belowTwenty[twnty];
        else{
            if(tens>0)s+=" "+belowHundred[tens];
            if(ones>0)s+=" "+belowTen[ones];
        }

        if(prev>0 && pos==1) s+=" Thousand";
        else if(prev>0 && pos==2) s+=" Million";
        else if(prev>0 && pos==3) s+=" Billion";

        num=num/1000;
        return solve(num,pos+1)+s;
        
    }
    string numberToWords(int num) {
        if(num==0) return "Zero";
        string s= solve(num,0);
        if(s[0]==' '){
            s.erase(0,1);
        }
        return s;
    }
};