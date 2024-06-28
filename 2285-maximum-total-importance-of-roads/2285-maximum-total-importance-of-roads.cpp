class Solution {
public:
    // Define a type alias for long long as ll
    #define ll long long

    // Function to calculate the maximum importance of the city
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        // Create a vector to store the in-degree (number of connections) for each city
        vector<ll> indeg(n, 0);

        // Iterate over each road to count the in-degrees for each city
        for (int i = 0; i < roads.size(); i++) {
            indeg[roads[i][0]]++;
            indeg[roads[i][1]]++;
        }

        // Sort the in-degrees in descending order
        sort(indeg.begin(), indeg.end(), greater<ll>());

        // Initialize variables to store the result and the current importance value
        long long ans = 0;
        long long ctr = n;

        // Assign importance values to cities based on their in-degrees
        for (int i = 0; i < n; i++) {
            ans += ctr * indeg[i];
            ctr--;
        }

        // Return the calculated maximum importance
        return ans;
    }
};
