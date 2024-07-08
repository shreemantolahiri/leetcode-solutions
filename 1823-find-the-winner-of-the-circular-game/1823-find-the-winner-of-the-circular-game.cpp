class Solution {
public:
    int findTheWinner(int n, int k) {
        vector<int> nums;
        for(int i=1;i<=n;i++) nums.push_back(i);
        k=k-1;
        int curr=0;
        while(nums.size()>1){
            int n=nums.size();
            curr=(curr+k)%n;
            cout<<nums[curr]<<endl;
            auto it=nums.begin()+curr;
            nums.erase(it);
        }

        return nums[0];
    }
};