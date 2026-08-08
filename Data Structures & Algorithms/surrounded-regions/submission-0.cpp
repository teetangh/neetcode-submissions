class Solution {

    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, -1, 0, 1};

    void bfs(int sr, int sc, vector<vector<char>>& board,
             vector<vector<bool>>& visited) {
        visited[sr][sc] = true;
        queue<pair<int, int>> q;
        q.push({sr, sc});
        int m = board.size();
        int n = board[0].size();

        while (!q.empty()) {
            auto node = q.front();
            q.pop();
            int x = node.first;
            int y = node.second;

            for (int k = 0; k < 4; k++) {
                int newX = x + dx[k];
                int newY = y + dy[k];

                if (newX >= 0 && newX < m && newY >= 0 && newY < n &&
                    !visited[newX][newY] && board[newX][newY] == 'O') {
                    q.push({newX, newY});
                    visited[newX][newY] = true;
                }
            }
        }
    }

public:
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();

        vector<vector<bool>> visited(m, vector<bool>(n, false));
        // 3 for loops
        for (int i = 0; i < m; i++) {
            if (i == 0) {
                for (int j = 0; j < n; j++) {
                    if (!visited[i][j] && board[i][j] == 'O')
                        bfs(i, j, board, visited);
                }
            } else if (i == (m - 1)) {
                for (int j = 0; j < n; j++) {
                    if (!visited[i][j] && board[i][j] == 'O')
                        bfs(i, j, board, visited);
                }
            }
        }

        for (int j = 0; j < n; j++) {
            if (j == 0) {
                for (int i = 0; i < m; i++) {
                    if (!visited[i][j] && board[i][j] == 'O')
                        bfs(i, j, board, visited);
                }
            } else if (j == (n - 1)) {
                for (int i = 0; i < m; i++) {
                    if (!visited[i][j] && board[i][j] == 'O')
                        bfs(i, j, board, visited);
                }
            }
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (!visited[i][j] && board[i][j] == 'O') {
                    board[i][j] = 'X';
                }
                visited[i][j] = true;
            }
        }
    }
};