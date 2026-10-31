class Solution {
public:
    int uniquePaths(vector<vector<int>>& grid) {
        const int MOD = 1e9+7;
        int m = grid.size(), n = grid[0].size();

        vector<array<long long, 2>> dp(n, {0, 0});
        dp[0][0] = 1;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i > 0) {
                    if (grid[i - 1][j] == 0) {
                        dp[j][0] = (dp[j][0] + dp[j][1]) % MOD;
                    } else {
                        dp[j][0] = dp[j][1];
                    }
                }

                if (j > 0) {
                    if (grid[i][j - 1] == 0) {
                        dp[j][1] = (dp[j - 1][0] + dp[j - 1][1]) % MOD;
                    } else {
                        dp[j][1] = dp[j - 1][0];
                    }
                }
            }
        }

        return (dp[n - 1][0] + dp[n - 1][1]) % MOD;
    }
};