class Solution {
    void dfs(vector<vector<char>>& grid, vector<vector<bool>>& visited, int x, int y) {
        visited[x][y] = true;
        int n = grid.size();
        int m = grid[0].size();

        int dx[4] = {-1, 0, 1, 0};
        int dy[4] = {0, -1, 0, 1};

        for (int k = 0; k < 4; k++) {
            int nx = x + dx[k];
            int ny = y + dy[k];
            if (nx >= 0 && nx < n && ny >= 0 && ny < m && grid[nx][ny] == '1' && !visited[nx][ny]) {
                dfs(grid, visited, nx, ny);
            }
        }
    }

   public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> visited(n, vector<bool>(m, false));

        int count = 0;
        for (int x = 0; x < n; x++) {
            for (int y = 0; y < m; y++) {
                if (grid[x][y] == '1' && !visited[x][y]) {
                    dfs(grid, visited, x, y);
                    count++;
                }
            }
        }

        return count;
    }
};
