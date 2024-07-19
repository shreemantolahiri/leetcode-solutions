class Solution {
public:
    bool dfs(int node, vector<int>& color,
             unordered_map<int, vector<int>>& mp) {
        // check with neighbours
        for (auto neighbour : mp[node]) {
            if (color[neighbour] != 0) {
                if (color[neighbour] == color[node])
                    return false;
            } else {
                // color the uncoloured
                color[neighbour] = 3 - color[node];
                if (!dfs(neighbour, color, mp))
                    return false;
            }
        }
        return true;
    }
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        unordered_map<int, vector<int>> mp;
        vector<int> color(n + 1, 0);
        for (int i = 0; i < dislikes.size(); i++) {
            int a = dislikes[i][0];
            int b = dislikes[i][1];

            mp[a].push_back(b);
            mp[b].push_back(a);
        }

        // for every component
        for (int i = 1; i <= n; i++) {
            if (color[i] == 0) {
                color[i] = 1;
                if (!dfs(i, color, mp))
                    return false;
            }
        }
        return true;
    }
};