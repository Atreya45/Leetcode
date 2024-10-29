class Solution {
public:
    #define mod 1000000007
    int rec(int m, int n, int maxMove, int row, int column,vector<vector<vector<int>>>&dp) {
        if (row < 0 || row >= m || column < 0 || column >= n) {
            return 1;
        }
        if (maxMove == 0) {
            return 0;
        }
        if(dp[maxMove][row][column]!=-1){
            return dp[maxMove][row][column];
        }
        int ans = 0;
        ans = (ans + rec(m, n, maxMove - 1, row + 1, column, dp)) % mod;
        ans = (ans + rec(m, n, maxMove - 1, row - 1, column, dp)) % mod;
        ans = (ans + rec(m, n, maxMove - 1, row, column + 1, dp)) % mod;
        ans = (ans + rec(m, n, maxMove - 1, row, column - 1, dp)) % mod;
        return dp[maxMove][row][column]=ans;
    }
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        vector<vector<vector<int>>> dp(maxMove + 1, vector<vector<int>>(m, vector<int>(n, -1)));
        int ans = rec(m, n, maxMove, startRow, startColumn,dp);
        return ans;
    }
};