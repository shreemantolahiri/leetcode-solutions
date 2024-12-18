class Solution {
public:
    int getIndex(char &c){
        if(c>='a' && c<='z') return c-'a';

        else return 26+c-'A';
    }
    bool cmp(vector<int> &smap,vector<int> &tmap){
        for(int i=0;i<52;i++){
            if(tmap[i]>smap[i]) return false;
        }

        return true;
    }
    string minWindow(string s, string t) {
        vector<int> tmap(52,0), smap(52,0);

        // for(auto c:s) smap[c-'A']++;
        for(char c:t) {
            tmap[getIndex(c)]++;
        }

        int left=0,right=0;
        int minLen=INT_MAX;
        int minInd=0;

        for(;right<s.length();right++){
            smap[getIndex(s[right])]++;
            
            while(cmp(smap,tmap)){
                if(right-left+1<minLen){
                    minInd=left;
                    minLen=right-left+1;
                }
                //remove
                smap[getIndex(s[left])]--;
                left++;
            }
        }
        if(minLen==INT_MAX) return "";
        string res=s.substr(minInd,minLen);

        return res;
    }
};