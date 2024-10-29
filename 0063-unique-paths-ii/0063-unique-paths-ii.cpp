class Solution {
public:

    int rec(vector<vector<int>>& obstacleGrid,int i,int j,vector<vector<int>> &dp){
        int m=obstacleGrid.size();
        int n=obstacleGrid[0].size();
        if(i==m-1&&j==n-1){
            return 1;
        }
        if(i>=m||j>=n){
            return 0;
        }
        if(obstacleGrid[i][j]==1){
            return 0;
        }
        if (dp[i][j] != -1) {
            return dp[i][j];
        }
        return dp[i][j]=rec(obstacleGrid,i+1,j,dp)+rec(obstacleGrid,i,j+1,dp);
    }

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m=obstacleGrid.size();
        int n=obstacleGrid[0].size();
        if(obstacleGrid[0][0]==1||obstacleGrid[m-1][n-1]==1){
            return 0;
        }\
        vector<vector<int>> dp(m+1, vector<int>(n+1, -1));
        return rec(obstacleGrid,0,0,dp);
    }
};