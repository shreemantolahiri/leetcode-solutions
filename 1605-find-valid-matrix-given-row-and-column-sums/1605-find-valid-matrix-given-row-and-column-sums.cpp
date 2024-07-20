class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
        int n=rowSum.size();
        int m=colSum.size();
        vector<vector<int>> mat(n,vector<int>(m,0));
        vector<pair<int,int>> rows,cols;

        for(int i=0;i<n;i++){
            rows.push_back({rowSum[i],i});
        }
        for(int i=0;i<m;i++){
            cols.push_back({colSum[i],i});
        }

        sort(rows.begin(),rows.end());
        sort(cols.begin(),cols.end());
        // for(int i=0;i<n;i++){
        //     cout<<rows[i].first<<" "<<rows[i].second<<endl;
        // }
        // cout<<"cols= "<<endl;
        // for(int i=0;i<m;i++){
        //     cout<<cols[i].first<<" "<<cols[i].second<<endl;
        // }
        int r=0;
        int c=0;
        while(r<n && c<m){
            if(rows[r].first<cols[c].first){
                //fill r first
                mat[rows[r].second][cols[c].second]=rows[r].first;
                
                cols[c].first-=rows[r].first;
                r++;
            }
            else{
                //fill c first
                mat[rows[r].second][cols[c].second]=cols[c].first;
                
                rows[r].first-=cols[c].first;
                c++;
            }
        }

        return mat;
    }
};