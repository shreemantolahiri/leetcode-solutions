class Solution {
public:
  int numFriendRequests(vector<int>& ages) {
    std::sort(ages.begin(), ages.end());
    int n = ages.size(), count = 0;

    for (int i = 0; i < n; ++i) {
      int low_index = std::upper_bound(ages.begin(), ages.end(), (ages[i] / 2) + 7) - ages.begin();
      int high_index = std::upper_bound(ages.begin(), ages.end(), ages[i]) - ages.begin();
      count += std::max(high_index - low_index - 1, 0);
    }

    return count;
  }
};
