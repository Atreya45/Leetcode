class Solution {
public:
    int minimumObstacles(vector<vector<int>>& grid) {
        int dir[5] = {0, 1, 0, -1, 0};
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> dp(n, vector<int>(m, INT_MAX));
        dp[0][0] = 0;
        deque<pair<int, int>> q;
        q.push_back({0, 0});

        while (!q.empty()) {
            auto cur = q.front();
            q.pop_front();
            int x = cur.first;
            int y = cur.second;

            for (int i = 0; i < 4; i++) {
                int dx = x + dir[i];
                int dy = y + dir[i + 1];

                if (dx >= 0 && dy >= 0 && dx < n && dy < m &&
                    dp[dx][dy] == INT_MAX) {
                    dp[dx][dy] = dp[x][y] + (grid[dx][dy] == 1);
                    if (grid[dx][dy]) {
                        q.push_back({dx, dy});
                    } else
                        q.push_front({dx, dy});
                }
            }
        }

        return dp[n - 1][m - 1];
    }
};