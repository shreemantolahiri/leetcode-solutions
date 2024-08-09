class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
        vector<vector<int>> res;
        int n=rows; int m=cols;
        int count=0;
        int total=rows*cols;

        int i=rStart; int j=cStart;
        int diff=1;
        while(count<total){
            //right
            for(int k=0;k<diff;k++){
                if(i>=0 && j>=0 && i<n && j<m){
                    res.push_back({i,j});
                    count++;
                }
                j++;
            }
            //down
            for(int k=0;k<diff;k++){
                if(i>=0 && j>=0 && i<n && j<m){
                    res.push_back({i,j});
                    count++;
                }
                i++;
            }
            if(count>=total) break;
            diff++; //inc the jump

            //left
            for(int k=0;k<diff;k++){
                if(i>=0 && j>=0 && i<n && j<m){
                    res.push_back({i,j});
                    count++;
                }
                j--;
            }
            //up
            for(int k=0;k<diff;k++){
                if(i>=0 && j>=0 && i<n && j<m){
                    res.push_back({i,j});
                    count++;
                }
                i--;
            }

            diff++; //inc the jump

        }

        return res;
    }
};