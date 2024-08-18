class Solution {
public:
    long long maxPoints(vector<vector<int>>& points) {
        int n=points.size();
        int m=points[0].size();

        vector<long long> prev(m,0);
        vector<long long> curr(m,0);
        for(int i=0;i<m;i++){
            prev[i]=points[0][i];
        }
        if(n==1) return *max_element(prev.begin(),prev.end());
        for(int i=1;i<n;i++){
            for(int j=0;j<m;j++){
                cout<<prev[j]<<" ";
                for(int k=0;k<m;k++){
                    curr[j]=max(curr[j],(long long)points[i][j]+prev[k]-abs(j-k));
                    // temp=max((long long)points[i][k]-abs(j-k),temp);
                    
                }
                // prev[j]=prev[j]+temp;
                
            }
            cout<<endl;
            prev=curr;
            fill(curr.begin(), curr.end(), 0);
        }

        return *max_element(prev.begin(),prev.end());
    }
};