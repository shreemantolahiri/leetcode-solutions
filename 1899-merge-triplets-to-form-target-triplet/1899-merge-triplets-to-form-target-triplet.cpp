class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        bool found1 = false, found2 = false, found3 = false;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < triplets.size(); j++) {
                if (i == 0 && triplets[j][i] == target[i]) {
                    if (triplets[j][1] <= target[1] &&
                        triplets[j][2] <= target[2]) {
                        found1 = true;
                        break;
                    }
                }
                if (i == 1 && triplets[j][i] == target[i]) {
                    if (triplets[j][0] <= target[0] &&
                        triplets[j][2] <= target[2]) {
                        found2 = true;
                        break;
                    }
                }
                else if (i == 2 && triplets[j][i] == target[i]) {
                    if (triplets[j][1] <= target[1] &&
                        triplets[j][0] <= target[0]) {
                        found3 = true;
                        break;
                    }
                }
            }
        }
        return (found1 && found2 && found3);

        
    }
};