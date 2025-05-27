class Solution {
    vector<vector<int>> dp;

    int maxSatisfactionHelper(vector<int>& a, int n, int i, int f) {
        if (i == n) return 0;
        if (dp[i][f] != -1) return dp[i][f];

        int take = a[i] * f + maxSatisfactionHelper(a, n, i + 1, f + 1);
        int skip = maxSatisfactionHelper(a, n, i + 1, f);

        return dp[i][f] = max(take, skip);
    }

public:
    int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.begin(), satisfaction.end());
        int n = satisfaction.size();
        dp = vector<vector<int>>(n, vector<int>(n + 1, -1)); 
        return maxSatisfactionHelper(satisfaction, n, 0, 1);
    }
};
