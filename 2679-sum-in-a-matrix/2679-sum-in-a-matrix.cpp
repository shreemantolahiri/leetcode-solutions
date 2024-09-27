class Solution {
public:
    int matrixSum(vector<vector<int>>& nums) {
        //variable to store count
        int count=0;
        int n=nums.size();
        int m=nums[0].size();

        for(int j=0;j<m;j++){
            int maxEle=INT_MIN;
            for(int i=0;i<n;i++){
                maxEle=max(maxEle,nums[i][j]);
            }

            count+=maxEle;
        }

        return count;
        
    }
};