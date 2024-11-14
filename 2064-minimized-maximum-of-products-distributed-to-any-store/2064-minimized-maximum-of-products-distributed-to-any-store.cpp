class Solution {
public:
    bool canBeDistributed(vector<int>& quantities,int k,int n){
        int ind=0; int m=quantities.size();
        int count=0;
        for(int i=0;i<m;i++){
            float f1=quantities[i];
            float f2=ceil(f1/k);

            count+=(int)f2;
        }
        if(count<=n) return true;
        else return false;
    }
    int minimizedMaximum(int n, vector<int>& quantities) {
        int maxNo=-1;
        for(int i:quantities){
            maxNo=max(maxNo,i);
        }
        cout<<maxNo<<endl;
        //Now that we have largest number, we know that at max
        //that much can be distributed
        int ans=maxNo;
        int low=1; int high=maxNo;
        while(low<=high){
            int mid=low+(high-low)/2;
            cout<<mid<<endl;
            if(canBeDistributed(quantities,mid,n)){
                high=mid-1;
                ans=min(ans,mid);
            }
            else{
                low=mid+1;
            }
        }

        return ans;

    }
};