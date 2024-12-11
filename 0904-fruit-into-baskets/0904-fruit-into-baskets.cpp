class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        //fruit, count
        unordered_map<int,int> mp;
        int maxLen=0;
        int l=0,r=0;
        int n=fruits.size();
        for(;r<n;r++){
            mp[fruits[r]]++;

            if(mp.size()<=2) maxLen=max(maxLen,r-l+1);
            else{
                mp[fruits[l]]--;
                if(mp[fruits[l]]==0) mp.erase(fruits[l]);
                l++;
            }
        }

        return maxLen;
    }
};