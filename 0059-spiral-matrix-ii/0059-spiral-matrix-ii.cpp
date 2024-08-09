class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int ctr=1;
        int top=0;
        int bottom=n-1;
        int left=0;
        int right=n-1;
        vector<vector<int>> mat(n,vector<int>(n,0));
        int j=0; int i=0;
        while(left<=right && top<=bottom){
            i=top;
            for(j=left;j<=right;j++){
                mat[i][j]=ctr;
                ctr++;
            }
            top++;
            j=right;
            for(i=top;i<=bottom;i++){
                mat[i][j]=ctr;
                ctr++;
            }
            right--;
            if(right<left) break;
            i=bottom;
            for(j=right;j>=left;j--){
                mat[i][j]=ctr;
                ctr++;
            }
            bottom--;
            if(top>bottom) break;
            j=left;
            for(i=bottom;i>=top;i--){
                mat[i][j]=ctr;
                ctr++;
            }
            left++;
        }

        return mat;
    }
};