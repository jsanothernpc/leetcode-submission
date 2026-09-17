class Solution {
public:
    int maxPathScore(vector<vector<int>>& grid, int k) {
        
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n,vector<int>(k + 1, -1)));
        dp[0][0][0]=0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 && j == 0) continue;
                int value = grid[i][j];
                int cost = (value == 0 ? 0 : 1);
                for (int c = 0; c <= k; c++) {
                    int best = -1;
                    // Come from above
                    if (i > 0 && dp[i - 1][j][c] != -1) {
                        best = max(best, dp[i - 1][j][c]);
                    }
                    // Come from left
                    if (j > 0 && dp[i][j - 1][c] != -1) {
                        best = max(best, dp[i][j - 1][c]);
                    }
                    if (best == -1) continue;
                    int newCost = c + cost;
                    if (newCost <= k) dp[i][j][newCost] = max(dp[i][j][newCost], best + value);
                }
            }
        }
        int ans = -1;
        for (int c = 0; c <= k; c++) {
            ans = max(ans, dp[m - 1][n - 1][c]);
        }
        return ans;
    }
};