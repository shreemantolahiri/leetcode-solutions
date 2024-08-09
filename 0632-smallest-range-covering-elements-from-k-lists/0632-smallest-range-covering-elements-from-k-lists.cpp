class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int n=nums.size();
        int range=0;
        for(int i=0;i<n;i++){
            range+=nums[i].size();
            // sort(nums[i].begin(),nums[i].end());
        }
        int res=INT_MAX;
        vector<int> ans={-1,-1};
        //now all sorted
        for(int i=0;i<range;i++){
            int smallest=nums[0][0];
            int ind=0;
            int largest=nums[0][0];
            for(int j=0;j<n;j++){
                cout<<nums[j].size()<<" ";
                if(nums[j].size()==0) break;
                if(smallest>nums[j][0]){
                    smallest=nums[j][0];
                    ind=j;
                }
                largest=max(largest,nums[j][0]);
            }
            if(largest-smallest<res){
                res=largest-smallest;
                ans={smallest,largest};
            }
            cout<<endl;
            nums[ind].erase(nums[ind].begin());
            if(nums[ind].size()==0) break;
        }

        return ans;
    }
};