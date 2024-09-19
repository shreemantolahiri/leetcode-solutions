class Solution {
public:
    int solve(int ind,vector<int>& nums){
        if(ind==nums.size()) return 1;
        int maxP=INT_MIN;
        int product=1;
        //pick
        for(int i=ind;i<nums.size();i++){
            product=product*nums[i];
            
            //skip
            int skip=solve(i+1,nums);
            maxP=max(product,skip);
        }
        cout<<ind<<"  "<<maxP<<endl;
        return maxP;
    }
    int maxProduct(vector<int>& nums) {
        

        return solve(0,nums);
    }
};