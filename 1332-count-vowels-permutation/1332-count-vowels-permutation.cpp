#include <vector>
using namespace std;

class Solution {
public:
    int rec(int n, int i, int c, vector<vector<int>>& dp) {
        if (c == 0) {
            return 1;
        }
        
        if (dp[i][c] != -1) {
            return dp[i][c];
        }
        
        int sum = 0;
        
        if (i == 0) {
            sum = (sum + rec(n, 1, c - 1, dp)) % 1000000007;
        } else if (i == 1) {
            sum = (sum + rec(n, 0, c - 1, dp)) % 1000000007;
            sum = (sum + rec(n, 2, c - 1, dp)) % 1000000007;
        } else if (i == 2) {
            sum = (sum + rec(n, 0, c - 1, dp)) % 1000000007;
            sum = (sum + rec(n, 1, c - 1, dp)) % 1000000007;
            sum = (sum + rec(n, 3, c - 1, dp)) % 1000000007;
            sum = (sum + rec(n, 4, c - 1, dp)) % 1000000007;
        } else if (i == 3) {
            sum = (sum + rec(n, 2, c - 1, dp)) % 1000000007;
            sum = (sum + rec(n, 4, c - 1, dp)) % 1000000007;
        } else if (i == 4) {
            sum = (sum + rec(n, 0, c - 1, dp)) % 1000000007;
        }
        
        dp[i][c] = sum;
        return sum;
    }

    int countVowelPermutation(int n) {
        vector<vector<int>> dp(5, vector<int>(n + 1, -1));
        int ans = 0;
        for (int i = 0; i < 5; ++i) {
            ans = (ans + rec(n, i, n - 1, dp)) % 1000000007;
        }
        return ans;
    }
};
