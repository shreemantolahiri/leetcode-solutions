class Solution {
public:
    int firstOne(vector<int> &arr){
        int left=0;
        int right=arr.size()-1;

        while(left<=right){
            int mid=(left+right)/2;

            if(arr[mid]==1){
                right=mid-1;
            }
            else{
                left=mid+1;
            }
        }

        //left is the index of 1
        return arr.size()-left;
    }
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        int maxOnes=0; int ind=0;

        for(int i=0;i<mat.size();i++){
            sort(mat[i].begin(),mat[i].end());
            int noOfOnes=firstOne(mat[i]);

            if(noOfOnes>maxOnes){
                maxOnes=noOfOnes;
                ind=i;
            }
        }

        return {ind,maxOnes};
    }
};