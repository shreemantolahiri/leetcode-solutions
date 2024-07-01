class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int count=0;
        int m=arr[arr.size()-1];

         
        int ind=0;
        for(int i=1;i<=m;i++){
            if(ind>arr.size()) break;
            if(i==arr[ind]){
                ind++;
            }
            else{
                k--;
            }
            if(k==0) return i;
        }

        return m+k;
    }
};