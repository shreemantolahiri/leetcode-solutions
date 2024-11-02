class Solution {
public:
    bool checkAnagramWindow(int k,string s){
        int n=s.length();
        if(n%k!=0) return false;
        vector<int> prevCnt(26,0), currCnt(26,0);
        bool firstIter=true;
        
        for(int i=0;i<n;i+=k){
            int j_max=min(n,i+k);
            for(int j=i;j<j_max;j++){
                
                currCnt[s[j]-'a']++;
            }

            if(firstIter){
                firstIter=false;
            }
            else{
                //check with prev
                if(prevCnt!=currCnt) return false;
            }
            prevCnt=currCnt;
            fill(currCnt.begin(), currCnt.end(), 0);
        }
        return true;
    }
    int minAnagramLength(string s) {
        
        int n=s.length();
        int ans=n;

        // cout<<n<<endl;
        while(n>1){
            if(checkAnagramWindow(n,s)) ans=n;
            for(int i=2;i<=n;i++){
                if(n%i==0){
                    n/=i;
                    break;
                }
            }
        }
        if(checkAnagramWindow(n,s)) ans=n;
        return ans;
        
    }
};