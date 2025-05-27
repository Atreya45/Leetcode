class Solution {
    int mod = 1e9 + 7;
    vector<vector<vector<int>>> dp;

    int profitableSchemesHelper(int n, int minProfit, vector<int>& group,
                                vector<int>& profit, int index, int currPeople,
                                int currProfit) {
        if (currPeople > n)
            return 0;
        if (index == profit.size()) {
            return currProfit >= minProfit ? 1 : 0;
        }

        if (dp[index][currPeople][min(currProfit, minProfit)] != -1)
            return dp[index][currPeople][min(currProfit, minProfit)];

        int take = profitableSchemesHelper(n, minProfit, group, profit,
                                           index + 1, currPeople + group[index],
                                           currProfit + profit[index]);

        int skip = profitableSchemesHelper(n, minProfit, group, profit,
                                           index + 1, currPeople, currProfit);

        return dp[index][currPeople][min(currProfit, minProfit)] =
                   (take + skip) % mod;
    }

public:
    int profitableSchemes(int n, int minProfit, vector<int>& group,
                          vector<int>& profit) {
        int m = group.size();
        dp = vector<vector<vector<int>>>(
            m + 1, vector<vector<int>>(n + 1, vector<int>(minProfit + 1, -1)));
        int index = 0, currPeople = 0, currProfit = 0;
        return profitableSchemesHelper(n, minProfit, group, profit, index,
                                       currPeople, currProfit);
    }
};