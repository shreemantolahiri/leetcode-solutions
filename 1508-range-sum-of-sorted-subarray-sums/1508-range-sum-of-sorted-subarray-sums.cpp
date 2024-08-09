class Solution {
public:
    int mod=1000000007;
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        priority_queue<pair<int,int>,
        vector<pair<int,int>>,
        greater<pair<int,int>> > pq;

        vector<int> res;

        for(int i=0;i<n;i++){
            pq.push({nums[i],i});
        }

        while(!pq.empty()){
            auto it=pq.top();
            pq.pop();

            int sum=it.first;
            int ind=it.second;
            res.push_back(sum);
            if(ind!=n-1){
                sum=(sum+nums[ind+1])%mod;
                pq.push({sum,ind+1});
            }
        }

        int ans=0;
        for(int i=left-1;i<=right-1;i++){
            ans=(ans+res[i])%mod;
        }

        return ans;
    }
};