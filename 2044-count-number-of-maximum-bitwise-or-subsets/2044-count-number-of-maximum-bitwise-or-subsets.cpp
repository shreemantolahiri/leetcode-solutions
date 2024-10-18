class Solution {
public:
    int count=0;
    void solve(int mask,int ind, vector<int> &nums, int maxOr){
        if(ind==nums.size()) return;

        //skip
        solve(mask,ind+1,nums,maxOr);

        //pick
        mask=mask|nums[ind];
        if(mask==maxOr) count++;
        solve(mask,ind+1,nums,maxOr);

        return;
    }
    int countMaxOrSubsets(vector<int>& nums) {
        //max bitwise or is or of the entire array

        int maxOr=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            maxOr=maxOr | nums[i];
        }

        //generate all subsets
        solve(0,0,nums,maxOr);
        // cout<<maxOr<<endl;
        
        return count;
    }
};