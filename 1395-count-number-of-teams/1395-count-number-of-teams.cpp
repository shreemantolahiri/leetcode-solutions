class Solution {
public:
int LDSsolve(int ind,vector<int> &temp,vector<int>& rating){
        if(temp.size()==3) return 1;
        if(ind==rating.size()) return 0;

        //pick
        int pick=0;
        if(temp.size()==0 || rating[ind]<temp[temp.size()-1]){
            temp.push_back(rating[ind]);
            pick=LDSsolve(ind+1,temp,rating);
            temp.pop_back();
        }
        //not pick
        int skip=LDSsolve(ind+1,temp,rating);

        return pick+skip;
    }
    int LISsolve(int ind,vector<int> &temp,vector<int>& rating){
        if(temp.size()==3) return 1;
        if(ind==rating.size()) return 0;

        //pick
        int pick=0;
        if(temp.size()==0 || rating[ind]>temp[temp.size()-1]){
            temp.push_back(rating[ind]);
            pick=LISsolve(ind+1,temp,rating);
            temp.pop_back();
        }
        //not pick
        int skip=LISsolve(ind+1,temp,rating);

        return pick+skip;
    }
    int numTeams(vector<int>& rating) {
        //we check all possibilities
        int count=0;
        int n=rating.size();

        vector<int> temp;
        count+=LISsolve(0,temp,rating);
        temp.clear();
        count+=LDSsolve(0,temp,rating);

        return count;
    }
};