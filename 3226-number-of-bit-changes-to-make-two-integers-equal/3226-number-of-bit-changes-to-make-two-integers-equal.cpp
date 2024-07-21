class Solution {
public:
    int minChanges(int n, int k) {
        if(n==k) return 0;
        int count=0;
        cout<<"   "<<endl;
        while(n>0 && k>0){
            // cout<<n<<" "<<k<<endl;
            int ncontainsOne=n&1;
            int kcontainsOne=k&1;
            if(ncontainsOne==kcontainsOne){
                n=n>>1;
                k=k>>1;
                continue;
            }
            if(ncontainsOne==1 && kcontainsOne==0){
                count++;
            }
            else if(ncontainsOne==0 && kcontainsOne==1){
                return -1;
            }
            
            n=n>>1;
            k=k>>1;
        }
        cout<<n<<endl;
        while(n>0){
            int ncontainsOne=n&1;
            if(ncontainsOne) count++;
            n=n>>1;
        }
        if(k>0) return -1;
        return count;
    }
};