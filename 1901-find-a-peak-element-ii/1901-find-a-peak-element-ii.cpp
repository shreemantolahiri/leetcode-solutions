class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n=mat.size(); int m=mat[0].size();
        int left=0; int right=m-1;

        while(left<=right){
            int mid=(left+right)/2;
            cout<<left<<" "<<right<<endl;
            //find largest in the column
            int i=0; int j=mid;
            for(int k=1;k<n;k++){
                if(mat[k][mid]>mat[i][mid]) i=k;
            }
            int leftEle=-1;
            if(j>0) leftEle=mat[i][j-1];
            int rightEle=-1;
            if(j<m-1) rightEle=mat[i][j+1];

            if(mat[i][j]>rightEle && mat[i][j]>leftEle) return {i,j};
            else if(mat[i][j]<rightEle) left=mid+1;
            else right=mid-1;
        }

        return {};
    }
};