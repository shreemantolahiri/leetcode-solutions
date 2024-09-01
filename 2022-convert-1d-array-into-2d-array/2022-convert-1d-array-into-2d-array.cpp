class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        int s=original.size();

        if(m*n!=s) return {};
        vector<vector<int>> res(m,vector<int>(n,0));
        int ctr=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                res[i][j]=original[ctr++];
            }
        }

        return res;
    }
};