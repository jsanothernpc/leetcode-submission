class Solution {
public:
    int m, n;
    // Directions: Up, Right, Down, Left
    int dr[4] = {-1, 0, 1, 0};
    int dc[4] = {0, 1, 0, -1};
    vector<vector<int>> connections = {
        {},
        {0, 1, 0, 1}, // 1: Left, Right
        {1, 0, 1, 0}, // 2: Up, Down
        {0, 0, 1, 1}, // 3: Left, Down
        {0, 1, 1, 0}, // 4: Right, Down
        {1, 0, 0, 1}, // 5: Left, Up
        {1, 1, 0, 0}  // 6: Right, Up
    };

    bool dfs(int r, int c, vector<vector<int>>& grid,vector<vector<bool>>& vis) {
        if (r == m - 1 && c == n - 1) return true;
        vis[r][c] = true;
        int street = grid[r][c];
        for (int d = 0; d < 4; d++) {
            if (!connections[street][d]) continue;
            int nr = r + dr[d];
            int nc = c + dc[d];

            // Out of bounds
            if (nr < 0 || nr >= m || nc < 0 || nc >= n)
                continue;

            // Already visited
            if (vis[nr][nc]) continue;
            // Opposite direction:
            int opposite = (d + 2) % 4;
            if (!connections[grid[nr][nc]][opposite]) continue;
            if (dfs(nr, nc, grid, vis)) return true;
        }
        return false;
    }
    bool hasValidPath(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        vector<vector<bool>> vis(m, vector<bool>(n, false));
        return dfs(0, 0, grid, vis);
    }
};