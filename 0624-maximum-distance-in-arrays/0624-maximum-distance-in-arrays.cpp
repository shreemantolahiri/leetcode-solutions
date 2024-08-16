class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        priority_queue<pair<int,int>> maxQ;
        priority_queue<pair<int,int>, vector<pair<int,int>> , greater<pair<int,int>>> minQ;
        int ind=0;
        for(auto it:arrays){
            if(it.size()==1){
                maxQ.push({it[0],ind});
                minQ.push({it[0],ind});
            }
            else{
                minQ.push({it[0],ind});
                maxQ.push({it[it.size()-1],ind});
            }
            ind++;
        }

        auto low=minQ.top();
        auto high=maxQ.top();
        if(low.second!=high.second){
            return abs(low.first-high.first);
        }
        else{
            minQ.pop();
            maxQ.pop();
            int op1=abs(low.first-maxQ.top().first);
            int op2=abs(high.first-minQ.top().first);

            return max(op1,op2);
        }
    }
};