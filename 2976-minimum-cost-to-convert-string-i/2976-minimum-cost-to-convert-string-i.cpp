class Solution {
public:

    void dijkstra(vector<vector<long long>> &res, unordered_map<char,vector<pair<char,long long>>> &mp, char s){
        priority_queue< pair<long long,char>, vector<pair<long long,char>>, greater<pair<long long,char>>> pq;
        
        
            // char s=source[i];
            // res[s-'a'][s-'a']=0;
            pq.push({0,s});
            while(!pq.empty()){
                
                long long d=pq.top().first;
                char midNode=pq.top().second;
                pq.pop();
                for(auto &vec:mp[midNode]){
                    char node=vec.first;
                    long long wt=vec.second;

                    if(d+wt<res[s-'a'][node-'a']){
                        res[s-'a'][node-'a']=d+wt;
                        pq.push({d+wt,node});
                    }
                }
            }

        

        return;
    }

    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        
        vector<vector<long long>> res(26, vector<long long>(26,INT_MAX));

        //make a adjacency list
        unordered_map<char,vector<pair<char,long long>>> mp;

        for(int i=0;i<original.size();i++){
            mp[original[i]].push_back({changed[i],(long long)cost[i]});
        }

        //perform dijkstras algorithm
        for(int i=0;i<source.size();i++){
            dijkstra(res,mp,source[i]);
        }
        

        long long mincost=0;
        //now all shortest paths calculated 
        for(int i=0;i<source.size();i++){

                if(source[i]==target[i]) continue;

                if(res[source[i]-'a'][target[i]-'a']==INT_MAX) return -1;
                mincost+=res[source[i]-'a'][target[i]-'a'];
                
            
        }

        return mincost;
    }
};