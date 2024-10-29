class Solution {
public:
    int rec(vector<vector<int>>& grid, int m, int n, int row, int col, vector<vector<int>>& dp) {
        if (row < 0 || row >= m || col >= n) {
            return INT_MIN;
        }

        if (dp[row][col] != -1) return dp[row][col];

        int maxMoves = 0;

        if (row > 0 && col < n - 1 && grid[row - 1][col + 1] > grid[row][col]) {
            maxMoves = max(maxMoves, 1 + rec(grid, m, n, row - 1, col + 1, dp));
        }
        if (col < n - 1 && grid[row][col + 1] > grid[row][col]) {
            maxMoves = max(maxMoves, 1 + rec(grid, m, n, row, col + 1, dp));
        }
        if (row < m - 1 && col < n - 1 && grid[row + 1][col + 1] > grid[row][col]) {
            maxMoves = max(maxMoves, 1 + rec(grid, m, n, row + 1, col + 1, dp));
        }

        dp[row][col] = maxMoves;
        return maxMoves;
    }

    int maxMoves(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        int ans = 0;

        for (int i = 0; i < m; i++) {
            ans = max(ans, rec(grid, m, n, i, 0, dp));
        }

        return ans;
    }
};
