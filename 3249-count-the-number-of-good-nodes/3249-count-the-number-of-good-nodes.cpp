class Solution {
public:
    int count=0;
    vector<int> arr;
    int solve(int node,int par,unordered_map<int,vector<int>> &mp){
        int totalChildren=0;
        int prevChild=-1;
        bool goodNode=true;
        for(auto it:mp[node]){
            if(it!=par){
                int curr=0;
                if(arr[it]!=-1){
                    curr=arr[it];
                }
                else {
                    curr=solve(it,node,mp);
                    arr[it]=curr;
                }
                totalChildren+=curr;
                if(prevChild==-1){
                    prevChild=curr;
                }
                else if(prevChild!=curr){
                    goodNode=false;
                }
            }
        }

        if(goodNode) count++;

        return totalChildren+1;
    }
    int countGoodNodes(vector<vector<int>>& edges) {
        unordered_map<int,vector<int>> mp;
        for(auto it:edges){
            int a =it[0];
            int b=it[1];
            
            mp[a].push_back(b);
            mp[b].push_back(a);
        }
        arr.resize(mp.size()+1,-1);
        solve(0,-1,mp);

        return count;
    }
};