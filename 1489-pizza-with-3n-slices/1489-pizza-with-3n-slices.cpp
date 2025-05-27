class Solution {
    vector<vector<int>> dp;

    int maxSizeSlicesHelper(vector<int>& slices, int start, int end, int n) {
        if (n == 0 || start > end) return 0;
        if (dp[start][n] != -1) return dp[start][n];

        int take = slices[start] + maxSizeSlicesHelper(slices, start + 2, end, n - 1);
        int skip = maxSizeSlicesHelper(slices, start + 1, end, n);

        return dp[start][n] = max(take, skip);
    }

public:
    int maxSizeSlices(vector<int>& slices) {
        int sz = slices.size();
        int k = sz / 3;

        dp = vector<vector<int>>(sz, vector<int>(k + 1, -1));
        int case1 = maxSizeSlicesHelper(slices, 0, sz - 2, k);

        dp = vector<vector<int>>(sz, vector<int>(k + 1, -1));
        int case2 = maxSizeSlicesHelper(slices, 1, sz - 1, k);

        return max(case1, case2);
    }
};
