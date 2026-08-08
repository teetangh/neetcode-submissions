class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        queue<pair<pair<int, int>, int>> q;
        int fresh_count = 0;
        vector<vector<bool>> visited(m, vector<bool>(n, false));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) {
                    visited[i][j] = true;
                } else if (grid[i][j] == 1) {
                    fresh_count++;
                } else {
                    q.push({{i, j}, 0});
                    visited[i][j] = true;
                }
            }
        }

        int dx[4] = {-1, 0, 1, 0};
        int dy[4] = {0, -1, 0, 1};
        int rotten = 0;
        int timer = 0;
        while (!q.empty()) {
            auto node = q.front();
            q.pop();

            int x = node.first.first;
            int y = node.first.second;
            int time = node.second;
            timer = max(time, timer);
            for (int k = 0; k < 4; k++) {
                int newX = x + dx[k];
                int newY = y + dy[k];

                if (newX >= 0 && newX < m && newY >= 0 && newY < n &&
                    !visited[newX][newY] && grid[newX][newY] == 1) {
                    grid[newX][newY] = 2;
                    visited[newX][newY] = true;
                    q.push({{newX, newY}, time + 1});
                    rotten++;
                }
            }
        }
        if (rotten != fresh_count)
            return -1;
        return timer;
    }
};