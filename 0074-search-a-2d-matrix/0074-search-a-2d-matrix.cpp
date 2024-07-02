class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n=matrix.size(); int m=matrix[0].size();
        int left=0; int right=m*n-1;

        while(left<=right){
            int mid=(left+right)/2;
            cout<<mid<<endl;
            //get coordinates
            int i=mid/m;
            int j=mid-(i*m);

            if(matrix[i][j]==target) return true;
            else if(matrix[i][j]<target) left=mid+1;
            else right=mid-1;
        }

        return false;
    }
};