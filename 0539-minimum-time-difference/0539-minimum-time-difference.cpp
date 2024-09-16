class Solution {
public:
   
    int findMinDifference(vector<string>& timePoints) {
        
        // sort(timePoints.begin(),timePoints.end());
        int n=timePoints.size();
        vector<int> mins;
        for(int i=0;i<n;i++){
            string a=timePoints[i];
            int h1=(a[0]-'0')*10+a[1]-'0';
            int m1=(a[3]-'0')*10+a[4]-'0';
            int mins1=h1*60+m1;

            mins.push_back(mins1);
        
        }
        sort(mins.begin(),mins.end());
        int day=24*60;
        int ans=INT_MAX;
        for(int i=0;i<n-1;i++){
            int curr=mins[i];
            int next=mins[i+1];


            //curr is always smaller than next
            ans=min({ans,next-curr,curr+day-next});
        }
        //corner case
        ans=min({ans,mins[n-1]-mins[0],mins[0]+day-mins[n-1]});
        return ans;
    }
};