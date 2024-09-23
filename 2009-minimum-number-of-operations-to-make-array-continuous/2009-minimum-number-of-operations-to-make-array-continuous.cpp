class Solution {
public:
    int minOperations(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        set<int> st(nums.begin(),nums.end());
        int n=nums.size();
        for(int i=0;i<n;i++){
            cout<<nums[i]<<" ";
        }
        cout<<endl;
        vector<int> uniqueNum(st.begin(),st.end());

        int minChanges=INT_MAX;

        for(int i=0;i<uniqueNum.size();i++){
            int L=uniqueNum[i];
            int R=L+n-1; //maxLimit se ek zyada

            int ind=upper_bound(uniqueNum.begin(),uniqueNum.end(),R)-uniqueNum.begin();
            cout<<L<<" "<<R<<" "<<ind<<endl;
            // if(ind<n) cout<<nums[ind]<<endl;
            //how many more elements
            
            int correctRange=ind-i;
            minChanges=min(minChanges,n-correctRange);
        }

        return minChanges;
    }
};