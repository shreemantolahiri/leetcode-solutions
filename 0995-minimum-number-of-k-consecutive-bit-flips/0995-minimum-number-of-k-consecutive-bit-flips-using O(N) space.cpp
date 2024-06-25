class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        int res=0;
        int flipCount=0;
        int n=nums.size();
        // unordered_set<int> flips;
        vector<int> flips(n,0);
        for(int i=0;i<n;i++){
            //check if any flip done k indices before
            if(i>=k && flips[i-k]>0) flipCount--;

            if(nums[i]==0){
                //we need a flip
                if(flipCount%2==0){
                    //check if out of bound
                    if(i+k>n) return -1;
                    flipCount++;
                    res++;
                    // flips.insert(i);
                    flips[i]=1;
                }
            }
            else{
                //nums[i]==1
                if(flipCount%2==1){
                    //check if out of bound
                    if(i+k>n) return -1;
                    flipCount++;
                    res++;
                    flips[i]=1;
                }
            }
        }

        return res;
    }
};