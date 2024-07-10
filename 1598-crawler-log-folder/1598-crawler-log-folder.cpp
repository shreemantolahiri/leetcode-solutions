class Solution {
public:
    int minOperations(vector<string>& logs) {
        int level=0;
        for(int i=0;i<logs.size();i++){
            if(logs[i]=="./") continue;
            else if(logs[i]=="../") level=max(0,level-1);
            else level++;
        }

        return level;
    }
};