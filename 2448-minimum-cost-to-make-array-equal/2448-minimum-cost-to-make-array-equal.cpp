class Solution {
public:
    long long findCost(int target,vector<int>& nums, vector<int>& cost){
        long long totalCost=0;

        for(int i=0;i<nums.size();i++){
            totalCost+=(long long)cost[i]*abs(nums[i]-target);
        }

        return totalCost;
    }
    long long minCost(vector<int>& nums, vector<int>& cost) {
        //find the range possible
        int low=INT_MAX;
        int high=INT_MIN;
        int n=nums.size();
        for(int i=0;i<n;i++){
            low=min(low,nums[i]);
            high=max(high,nums[i]);
        }
        // long long res=LONG_MAX;
        while(low<=high){
            int mid=low+(high-low)/2;

            long long midCost=findCost(mid,nums,cost);

            long long preMidCost=findCost(mid-1,nums,cost);
            long long postMidCost=findCost(mid+1,nums,cost);

            if(preMidCost<midCost){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        
        return min(findCost(low,nums,cost),findCost(high,nums,cost));
       

    }
};