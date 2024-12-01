class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        unordered_set<int> st;

        for(int it:arr){
            //check if it's double exists
            if(st.count(it*2)){
                return true;
            }
            if(it%2==0 && st.count(it/2)) return true;          

            st.insert(it);
        }


        return false;
    }
};