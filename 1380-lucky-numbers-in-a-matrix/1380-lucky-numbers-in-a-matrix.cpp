class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        //we find max in every column then check if its min in the row
        int n=matrix.size();
        int m=matrix[0].size();
        vector<int> res;
        //we go col wise
        for(int j=0;j<m;j++){
            int maxi=0; int maxRow=0;
            //find maximum in the col
            for(int i=0;i<n;i++){
                if(matrix[i][j]>=maxi){
                    maxi=matrix[i][j];
                    maxRow=i;
                }
            }

            //check if its minimum in the row
            bool isMax=true;
            for(int k=0;k<m;k++){
                if(matrix[maxRow][k]>=maxi) continue;
                else isMax=false;
            }

            if(isMax) res.push_back(maxi);
        }

        return res;
    }
};