class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        long long res=0;
        int n=costs.size();
        //we go k rounds
        priority_queue< pair<int,int>,
        vector<pair<int,int>>,
        greater<pair<int,int>> > pq;

        //first push candidates
        int i=0;
        for(;i<candidates;i++) pq.push({costs[i],i});
        cout<<i<<endl;
        int j=n-1;
        for(;j>n-1-candidates;j--) {
            if(i>j) break;
            pq.push({costs[j],j});
            }
        cout<<j<<endl;
        while(k--){
            auto it=pq.top();
            pq.pop();
            int ind=it.second;
            res+=it.first;

            //check if all are pushed
            if(i>j) continue;
            else{
                //check which did we remove
                if(ind<i){
                    pq.push({costs[i],i});
                    i++;
                }
                else{
                    pq.push({costs[j],j});
                    j--;
                }
            }
        }

        return res;
    }
};