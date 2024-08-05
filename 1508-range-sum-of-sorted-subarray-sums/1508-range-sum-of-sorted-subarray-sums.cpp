class Solution {
public:
    int mod=1000000007;
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        
        vector<long long> arr;
        
        for(int i=0;i<n;i++){
            long long sum=0;
            for(int j=i;j<n;j++){
                sum=(sum+nums[j])%mod;
                arr.push_back(sum);
            }
        }

        sort(arr.begin(),arr.end());
        // for(auto i:arr) cout<<i<<" ";
        long long res=0;
        for(int i=left-1;i<=right-1;i++){
            res=(res+arr[i])%mod;
        }

        return res;
    }
};