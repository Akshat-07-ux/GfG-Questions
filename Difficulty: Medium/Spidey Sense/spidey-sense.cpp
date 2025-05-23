class Solution {
public:
    vector<vector<int>> findDistance(vector<vector<char>>& matrix, int M, int N) {
        vector<vector<int>> result(M, vector<int>(N, -1));
        queue<pair<int, int>> q;
        vector<vector<bool>> visited(M, vector<bool>(N, false));

        // Initialize the queue with bomb positions
        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < N; ++j) {
                if (matrix[i][j] == 'B') {
                    result[i][j] = 0;
                    q.push(make_pair(i, j));
                    visited[i][j] = true;
                } else if (matrix[i][j] == 'W') {
                    result[i][j] = -1;
                    visited[i][j] = true;
                }
            }
        }

        // Directions: up, down, left, right
        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};

        while (!q.empty()) {
            pair<int, int> p = q.front();
            q.pop();
            int x = p.first;
            int y = p.second;

            for (int d = 0; d < 4; ++d) {
                int nx = x + dx[d];
                int ny = y + dy[d];

                // Check bounds and if not visited and open space
                if (nx >= 0 && ny >= 0 && nx < M && ny < N && !visited[nx][ny] && matrix[nx][ny] == 'O') {
                    result[nx][ny] = result[x][y] + 1;
                    visited[nx][ny] = true;
                    q.push(make_pair(nx, ny));
                }
            }
        }

        return result;
    }
};