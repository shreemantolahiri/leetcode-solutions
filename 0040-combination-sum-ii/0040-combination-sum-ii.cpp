class Solution {
public:
vector<vector<int>> res;
    void solve(int ind,vector<int>& temp,vector<int>& c, int target){
        if(target==0){
            res.push_back(temp);
            return;
        }
        if(ind==c.size()) return;
        for(int i=ind;i<c.size();i++){
            if(i>ind && c[i-1]==c[i]){
                continue;
            }

            if(target>=c[i]){
                temp.push_back(c[i]);
                solve(i+1,temp,c,target-c[i]);
                temp.pop_back();
            }
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<int> temp;
        solve(0,temp,candidates,target);

        return res;
    }
};