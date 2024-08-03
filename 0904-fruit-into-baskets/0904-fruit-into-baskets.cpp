class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int types=0;
        int maxLen=1;
        unordered_map<int,int> mp;
        int l=0;
        for(int r=0;r<fruits.size();r++){
            if(mp[fruits[r]]==0){
                //new type
                if(types<2){
                    mp[fruits[r]]++;
                    types++;
                    maxLen=max(maxLen,r-l+1);
                }
                else{
                    //until becomes zero
                    while(l<=r && types==2){
                        mp[fruits[l]]--;
                        if(mp[fruits[l]]==0){
                            types--;
                        }
                        l++;
                    }
                    mp[fruits[r]]++;
                    types++;
                }
            }
            else{
                //old fruit
                mp[fruits[r]]++;
                    
                maxLen=max(maxLen,r-l+1);
            }
        }

        return maxLen;

    }
};