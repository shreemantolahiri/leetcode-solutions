class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        unordered_map<int,vector<pair<int,int>>> first,second,third;


        for(int i=0;i<triplets.size();i++){
            int a=triplets[i][0];
            int b=triplets[i][1];
            int c=triplets[i][2];

            if(a==target[0]) first[a].push_back({b,c});
            if(b==target[1]) second[b].push_back({a,c});
            if(c==target[2]) third[c].push_back({a,b});
        }

        //check if atleast all three exist
        if(first.count(target[0])==0 || second.count(target[1])==0 || third.count(target[2])==0) return false;

        //check individually
        bool found1=false,found2=false,found3=false;
        for(int i=0;i<3;i++){
            
            if(i==0){
                for(auto it:first[target[i]]){
                    if(it.first<=target[1] && 
                    it.second<=target[2]) found1=true;
                }
            }
            else if(i==1){
                // if(second.count(target[i])==0) return false;
                for(auto it:second[target[i]]){
                    if(it.first<=target[0] && 
                    it.second<=target[2]) found2=true;
                }
            }
            else{
                // if(third.count(target[i])==0) return false;
                for(auto it:third[target[i]]){
                    if(it.first<=target[0] && 
                    it.second<=target[1]) found3=true;
                }
            }
        }

        return (found1 && found2 && found3);

    }
};