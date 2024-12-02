class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        bool found1 = false, found2 = false, found3 = false;

        for (int j = 0; j < triplets.size(); j++) {
            if (triplets[j][0] == target[0]) {
                if (triplets[j][1] <= target[1] &&
                    triplets[j][2] <= target[2]) {
                    found1 = true;
                }
            }
            if (triplets[j][1] == target[1]) {
                if (triplets[j][0] <= target[0] &&
                    triplets[j][2] <= target[2]) {
                    found2 = true;
                }
            }
            if (triplets[j][2] == target[2]) {
                if (triplets[j][1] <= target[1] &&
                    triplets[j][0] <= target[0]) {
                    found3 = true;
                }
            }
        }

        return (found1 && found2 && found3);
    }
};