class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int ones=0;
        int n=nums.size();

        if(n<=2) return 0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==1) ones++;
        }
        

        int swaps=n-ones;
        // int zeroes=0;
        int zeroes=0;
        int ind=0;
        for(int i=0;i<ones;i++){
            if(nums[i]==0) zeroes++;
        }
        swaps=min(swaps,zeroes);
        ind=ones;
        while(ind!=ones-1){
            if(nums[ind]==0) zeroes++;
            if(ind>=ones){
                int prev=ind-ones;
                if(nums[prev]==0) zeroes--;
            }
            else{
                int prev=n+ind-ones;
                if(nums[prev]==0) zeroes--;
            }
            cout<<ind<<" "<<zeroes<<endl;
            swaps=min(swaps,zeroes);
            ind=(ind+1)%n;
        }

        return swaps;
    }
};