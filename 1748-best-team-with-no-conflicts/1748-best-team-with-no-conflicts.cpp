class Solution {
    int bestTeamScoreHelper(vector<pair<int, int>>& v, int i, int prevScore,
                            vector<vector<int>>& dp) {
        if (i == v.size())
            return 0;
        if (dp[i][prevScore + 1] != -1)
            return dp[i][prevScore + 1];

        int take = 0;
        if (prevScore == -1 || v[i].second >= v[prevScore].second) {
            take = v[i].second + bestTeamScoreHelper(v, i + 1, i, dp);
        }
        int skip = bestTeamScoreHelper(v, i + 1, prevScore, dp);
        return dp[i][prevScore + 1] = max(take, skip);
    }

public:
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        int n = scores.size();
        vector<pair<int, int>> v;
        for (int i = 0; i < n; i++)
            v.push_back({ages[i], scores[i]});
        sort(v.begin(), v.end());

        vector<vector<int>> dp(n, vector<int>(n + 1, -1));
        return bestTeamScoreHelper(v, 0, -1, dp);
    }
};
