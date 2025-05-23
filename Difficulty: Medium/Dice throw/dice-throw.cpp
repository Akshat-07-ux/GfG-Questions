class Solution {
    public:
    int noOfWays(int m, int n, int x) {
        vector<vector<int>> dp(n + 1, vector<int>(x + 1, 0));
        
        // Base case
        dp[0][0] = 1;

        // Fill dp table
        for (int i = 1; i <= n; ++i) { // i dice
            for (int j = 1; j <= x; ++j) { // total sum j
                for (int k = 1; k <= m; ++k) { // face value
                    if (j - k >= 0) {
                        dp[i][j] += dp[i - 1][j - k];
                    }
                }
            }
        }

        return dp[n][x];
    }
};