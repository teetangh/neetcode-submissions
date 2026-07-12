class Solution {
    void dfs(vector<vector<int>>& grid, vector<vector<bool>>& visited, int x,
             int y, int& currentArea) {
        visited[x][y] = true;
        int n = grid.size();
        int m = grid[0].size();
        currentArea++;

        int dx[4] = {-1, 0, 1, 0};
        int dy[4] = {0, -1, 0, 1};

        for (int k = 0; k < 4; k++) {
            int nx = x + dx[k];
            int ny = y + dy[k];
            if (nx >= 0 && nx < n && ny >= 0 && ny < m && grid[nx][ny] == 1 &&
                !visited[nx][ny]) {
                dfs(grid, visited, nx, ny, currentArea);
            }
        }
    }

public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> visited(n, vector<bool>(m, false));

        int maxArea = 0;
        for (int x = 0; x < n; x++) {
            for (int y = 0; y < m; y++) {
                int currentArea = 0;
                if (grid[x][y] == 1 && !visited[x][y]) {
                    dfs(grid, visited, x, y, currentArea);
                    if (currentArea > maxArea)
                        maxArea = currentArea;
                }
            }
        }

        return maxArea;
    }
};
