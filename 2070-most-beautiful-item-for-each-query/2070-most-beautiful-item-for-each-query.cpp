class Solution {
public:
    int findSmaller(int target, vector<int>& prices){
        int left=0; int right=prices.size()-1;

        while(left<=right){
            int mid=left+(right-left)/2;

            if(prices[mid]>target) right=mid-1;
            else left=mid+1;
        }

        if(right>=0 && right<prices.size()) return prices[right];
        return -1;
    }
    vector<int> maximumBeauty(vector<vector<int>>& items,
                              vector<int>& queries) {
        sort(items.begin(), items.end());
        int n = items.size();
        unordered_map<int, int> mp;
        mp[-1]=0;
        int maxN = INT_MIN;
        vector<int> prices;
        for (int i = 0; i < n; i++) {
            int price = items[i][0];
            int beauty = items[i][1];

            maxN = max(maxN, beauty);
            if (mp.find(price) == mp.end())
                prices.push_back(price);
            mp[price] = maxN;
        }

        vector<int> res;

        for (int i = 0; i < queries.size(); i++) {
            int q = queries[i];

            if (mp.find(q) != mp.end())
                res.push_back(mp[q]);
            else {
                //find smaller than q

                int ind=findSmaller(q,prices);

                res.push_back(mp[ind]);
            }
        }

        return res;
    }
};