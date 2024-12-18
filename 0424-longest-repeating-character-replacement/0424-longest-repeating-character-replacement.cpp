class Solution {
public:
    int characterReplacement(string s, int k) {
        int n=s.length();

        int res=0;
        int left=0,right=0;
        vector<int> mp(26,0);
        int maxf=0;
        for(;right<n;right++){
            mp[s[right]-65]++;

            maxf=max(maxf,mp[s[right]-65]);

            int toChange=right-left+1-maxf;
            if(toChange>k){
                mp[s[left]-65]--;
                left++;
            }
            

            if(toChange<=k) res=max(res,right-left+1);

        }

        return res;
    }
};