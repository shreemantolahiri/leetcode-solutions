class Solution {
public:
    // Directions for movement: right, down, left, up
    vector<int> dx = {1, 0, -1, 0};
    vector<int> dy = {0, -1, 0, 1};

    // Function to check if the next cell (i, j) is a valid island cell
    bool validIsland(int x, int y, int i, int j, vector<vector<int>>& vis,
                     vector<vector<int>>& heights) {
        int n = vis.size();
        int m = vis[0].size();
        // Check if the indices are out of bounds or if the cell has already been visited
        if (i < 0 || j < 0 || i >= n || j >= m || vis[i][j] == 1)
            return false;

        // Check if the next cell has a height greater than or equal to the current cell
        if (heights[x][y] <= heights[i][j])
            return true;
        else
            return false;
    }

    // Breadth-First Search (BFS) function to explore reachable cells
    void BFS(queue<pair<int, int>>& q, vector<vector<int>>& vis,
             vector<vector<int>>& heights) {
        int n = vis.size();
        int m = vis[0].size();
        while (!q.empty()) {
            // Get the front element of the queue
            auto it = q.front();
            int x = it.first;
            int y = it.second;
            q.pop();

            // Explore all 4 directions from the current cell
            for (int k = 0; k < 4; k++) {
                int new_x = x + dx[k];
                int new_y = y + dy[k];

                // If the new cell is a valid island, mark it and push it to the queue
                if (validIsland(x, y, new_x, new_y, vis, heights)) {
                    vis[new_x][new_y] = 1;
                    q.push({new_x, new_y});
                }
            }
        }
        return;
    }

    // Main function to find cells that can reach both the Pacific and Atlantic oceans
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        // Get the dimensions of the grid
        int n = heights.size();
        int m = heights[0].size();

        // Grid to track cells reachable from the Pacific Ocean
        vector<vector<int>> pacificOcean(n, vector<int>(m, 0));

        // Queue to hold the boundary cells for BFS starting from the Pacific Ocean
        queue<pair<int, int>> q;
        for (int i = 0; i < n; i++) {
            pacificOcean[i][0] = 1;  // Mark the left boundary (Pacific side)
            q.push({i, 0});          // Add to queue
        }
        for (int j = 0; j < m; j++) {
            pacificOcean[0][j] = 1;  // Mark the top boundary (Pacific side)
            q.push({0, j});          // Add to queue
        }

        // Perform BFS for the Pacific Ocean
        BFS(q, pacificOcean, heights);

        // Clear the queue to reuse it for the Atlantic Ocean
        while (!q.empty())
            q.pop();

        // Grid to track cells reachable from the Atlantic Ocean
        vector<vector<int>> atlanticOcean(n, vector<int>(m, 0));
        
        // Add the right and bottom boundaries to the queue for BFS starting from the Atlantic Ocean
        for (int i = 0; i < n; i++) {
            atlanticOcean[i][m - 1] = 1;  // Right boundary (Atlantic side)
            q.push({i, m - 1});           // Add to queue
        }
        for (int j = 0; j < m; j++) {
            atlanticOcean[n - 1][j] = 1;  // Bottom boundary (Atlantic side)
            q.push({n - 1, j});           // Add to queue
        }

        // Perform BFS for the Atlantic Ocean
        BFS(q, atlanticOcean, heights);

        // Result vector to store cells that can reach both oceans
        vector<vector<int>> res;

        // Check for cells that are reachable from both oceans
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (atlanticOcean[i][j] == 1 && pacificOcean[i][j] == 1) {
                    res.push_back({i, j});  // Add cell to result
                }
            }
        }

        return res;  // Return the result
    }
};
