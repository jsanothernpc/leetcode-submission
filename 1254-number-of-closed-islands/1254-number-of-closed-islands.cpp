class Solution {
public:
    int m, n;
    vector<vector<int>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    bool bfs(vector<vector<int>>& grid, int r, int c,
            vector<vector<int>>& visi) {
        queue<pair<int, int>> q;
        q.push({r, c});

        bool closed = true;

        while (!q.empty()) {
            auto [nr, nc] = q.front();
            q.pop();

            if (nr == 0 || nr == m - 1 || nc == 0 || nc == n - 1) {
                closed = false;
            }

            for (auto d : dir) {
                int i = nr + d[0];
                int j = nc + d[1];

                if (i >= 0 && i < m && j >= 0 && j < n && grid[i][j] == 0 && !visi[i][j]){
                    visi[i][j] = 1;
                    q.push({i, j});
                }
            }
        }
        return closed;
    }
    int closedIsland(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();

        vector<vector<int>> visited(m, vector<int>(n, 0));
        int res = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0 && !visited[i][j]) {
                    if (bfs(grid, i, j, visited))
                        res++;
                }
            }
        }

        return res;
    }
};