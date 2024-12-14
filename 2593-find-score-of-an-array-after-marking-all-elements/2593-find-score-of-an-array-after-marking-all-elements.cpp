class Solution {
public:
    long long findScore(vector<int>& nums) {
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        int n=nums.size();
        for(int i=0;i<n;i++){
            pq.push({nums[i],i});
        }
        long long res=0;
        while(!pq.empty()){
            auto it=pq.top();
            pq.pop();

            int ind=it.second;
            int num=it.first;

            if(nums[ind]==-1) continue;
            else{
                res+=num;
                nums[ind]=-1;
                if(ind>0) nums[ind-1]=-1;
                if(ind<n-1) nums[ind+1]=-1;
            }
        }

        return res;

    }
};