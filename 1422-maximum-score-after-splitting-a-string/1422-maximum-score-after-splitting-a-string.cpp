class Solution {
public:
    int maxScore(string s) {
        int n=s.length();
        vector<int> pref(n,0), suff(n,0);

        int zero=0;
        for(int i=0;i<n;i++){
            if(s[i]=='0') zero++;

            pref[i]=zero;
        }
        int ans=0;
        int ones=0;
        for(int i=n-1;i>=0;i--){
            if(s[i]=='1') ones++;

            suff[i]=ones;

            // ans=max(ans,pref[i]+ones);
        }
        
        for(int left=0;left<=n-2;left++){
            ans=max(ans,pref[left]+suff[left+1]);
        }

        return ans;
    }
};