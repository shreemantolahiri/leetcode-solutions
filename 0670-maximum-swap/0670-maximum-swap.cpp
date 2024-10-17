class Solution {
public:
    int maximumSwap(int num) {
        string s=to_string(num);
        int n=s.length();
        vector<int> nextLargest(n,0);
        nextLargest[n-1]=n-1;
        for(int i=n-2;i>=0;i--){
            int curr=(s[i]-'0');
            int prev=(s[nextLargest[i+1]]-'0');
            if(curr>=prev){
                nextLargest[i]=i;
            }
            else{
                nextLargest[i]=nextLargest[i+1];
            }
        }


        //we start from left
        for(int i=0;i<n;i++){
            if(nextLargest[i]!=i){
                char c=s[i];
                s[i]=s[nextLargest[i]];
                s[nextLargest[i]]=c;
                break;
            }

        }
        int res=stoi(s);
        return res;
    }
};