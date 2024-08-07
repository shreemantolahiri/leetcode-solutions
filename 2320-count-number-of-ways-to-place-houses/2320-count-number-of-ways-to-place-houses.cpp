class Solution {
public:
    int dp[10001][5];
    int mod = 1000000007;

    int solve(int prev, int ind, int n) {
        if (ind == n) return 1;

        if (dp[ind][prev] != -1) return dp[ind][prev];

        int count = 0;
        // Pick none of the houses
        count = (count + solve(0, ind + 1, n)) % mod;

        // Conditions for placing different types of houses
        if (prev != 1 && prev != 3) count = (count + solve(1, ind + 1, n)) % mod;
        if (prev != 2 && prev != 3) count = (count + solve(2, ind + 1, n)) % mod;
        if (prev == 0 || prev == 4) count = (count + solve(3, ind + 1, n)) % mod;

        dp[ind][prev] = count; // Store result in dp table
        return count;
    }

    int countHousePlacements(int n) {
        memset(dp, -1, sizeof(dp)); // Initialize dp array with -1
        return solve(4, 0, n);
    }
};
