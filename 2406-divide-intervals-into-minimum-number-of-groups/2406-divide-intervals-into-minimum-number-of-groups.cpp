class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());

        priority_queue<int, vector<int>, greater<int>> pq;
        int maxSize=0;
        for(int i=0;i<intervals.size();i++){
            cout<<intervals[i][0]<<" "<<intervals[i][1]<<endl;
            if(pq.empty()){
                pq.push(intervals[i][1]);
            }
            else{
                //check if not overlaps
                if(pq.top()<intervals[i][0]){
                    //already ended
                    pq.pop();
                }
                //insert new endtime
                pq.push(intervals[i][1]);
            }

            maxSize=max(maxSize,(int)pq.size());
        }

        return maxSize;
    }
};