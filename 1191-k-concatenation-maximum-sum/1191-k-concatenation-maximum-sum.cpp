class Solution {
public:
    // #define mod 1e9+7;
    int kConcatenationMaxSum(vector<int>& arr, int k) {
        int mod=1e9+7;
        int n=arr.size();

        long long kadaneSum=0;
        long long sum=0;
        long long maxPref=0;
        long long maxSuff=0;
        for(int i=0;i<n;i++){
            sum=(sum+arr[i])%mod;

            if(sum<0) sum=0;

            kadaneSum=max(kadaneSum,sum)%mod;
        }

        //now we have kadane
        if(k==1) return kadaneSum;

        //for k>1 we need maxPref and maxSuff
        sum=0;
        for(int i=0;i<n;i++){
            sum=(sum+arr[i])%mod;
            maxPref=max(maxPref,sum);
        }
        long long totalSum=sum;
        if(totalSum<0) totalSum=0;
        sum=0;

        //suffix
        for(int i=n-1;i>=0;i--){
            sum=(sum+arr[i])%mod;
            maxSuff=max(maxSuff,sum);
        }


        //we have three options
        long long op1=kadaneSum;
        //taking k*totalSum
        long long op2=((k)*totalSum%mod)%mod;
        long long op3=(((k-2)*totalSum%mod)%mod+maxPref+maxSuff)%mod;
        long long res=max(op1,op2)%mod;
        res=max(op3,res)%mod;
        return res;
    }
};