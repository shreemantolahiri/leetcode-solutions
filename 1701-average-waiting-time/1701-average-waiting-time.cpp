class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        double wt=0;
        double time=1;

        sort(customers.begin(),customers.end());
        int n=customers.size();
        for(int i=0;i<n;i++){
            time=max(time,(double)customers[i][0]);

            time+=(double)customers[i][1];
            if(time>customers[i][0]){
                wt+=time-(double)customers[i][0];
            }
        }

        return wt/n;
    }
};