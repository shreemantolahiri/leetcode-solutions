class Solution {
public:
    bool check(vector<int>& target, vector<int>& arr){
        int n=target.size(); int m=arr.size();

        if(m!=n) return false;

        for(int i=0;i<n;i++){
            if(target[i]!=arr[i]) return false;
        }

        return true;
    }
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        sort(target.begin(),target.end());
        sort(arr.begin(),arr.end());

        return target==arr;
        // return check(target,arr);
    }
};