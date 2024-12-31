class Solution {
public:
    int rec(vector<int>& days, vector<int>& costs, int index, vector<int>& dp) {
        if (index >= days.size()) {
            return 0;
        }
        if (dp[index] != -1) {
            return dp[index];
        }
        int one = costs[0] + rec(days, costs, index + 1, dp);
        int i = index;
        while (i < days.size() && days[i] < days[index] + 7) {
            i++;
        }
        int seven = costs[1] + rec(days, costs, i, dp);
        i = index;
        while (i < days.size() && days[i] < days[index] + 30) {
            i++;
        }
        int thirty = costs[2] + rec(days, costs, i, dp);
        int ans = min(one, min(seven, thirty));
        return dp[index] = ans;
    }
    int tab(vector<int>& days, vector<int>& costs) {
        vector<int> dp(days.size() + 1, 0);
        for (int index = days.size() - 1; index >= 0; index--) {
            int one = costs[0] + dp[index + 1];
            int i = index;
            while (i < days.size() && days[i] < days[index] + 7) {
                i++;
            }
            int seven = costs[1] + dp[i];
            i = index;
            while (i < days.size() && days[i] < days[index] + 30) {
                i++;
            }
            int thirty = costs[2] + dp[i];
            dp[index] = min(one, min(seven, thirty));
        }
        return dp[0];
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        // int index = 0;
        // vector<int> dp(days.size() + 1, -1);
        // int ans = rec(days, costs, index, dp);
        int ans=tab(days, costs);
        return ans;
    }
};