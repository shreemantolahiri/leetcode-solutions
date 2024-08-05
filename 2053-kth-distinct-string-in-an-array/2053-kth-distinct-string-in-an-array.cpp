class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        unordered_map<string,int> mp;
        int ct=0;
        for(int i=0;i<arr.size();i++){
            mp[arr[i]]++;
        }
        for(int i=0;i<arr.size();i++){
            if(mp[arr[i]]==1){
                ct++;
                if(ct==k) return arr[i];
            }
        }
        return "";

    }
};