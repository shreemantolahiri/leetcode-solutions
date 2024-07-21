class Solution {
public:
    int maxOperations(string s) {
        int n=s.length();
        int left=0;
        int right=0;
        int count=0;
        int ones=0;
        int currCount=0;
        bool foundZero=false;
        for(int i=0;i<n;i++){
            // cout<<s[i]<<"  count: "<<count<<" ones"<<ones<<"  currentcount"<<currCount<<endl;
            if(i>0 && s[i]=='0' && s[i-1]=='1'){
                count+=(currCount+ones);
                ones+=currCount;
                currCount=0;
            }
            else if(s[i]=='0') continue;
            else{
                // ones++;
                currCount++;
            }
            // cout<<s[i]<<"  count: "<<count<<" ones"<<ones<<"  currentcount"<<currCount<<endl;
        }
        
        return count;
    }
};