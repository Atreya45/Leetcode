class Solution {
    bool isPalindrome(int l, int r, string& s) {
        while (l < r) {
            if (s[l] != s[r])
                return false;
            l++, r--;
        }
        return true;
    }

    int minCutHelper(string& s, int index, vector<int>& dp) {
        if (index == s.size())
            return 0;
        if (dp[index] != -1)
            return dp[index];

        int mini = INT_MAX;
        for (int i = index; i < s.size(); ++i) {
            if (isPalindrome(index, i, s)) {
                int cuts = 1 + minCutHelper(s, i + 1, dp);
                mini = min(mini, cuts);
            }
        }
        return dp[index] = mini;
    }

public:
    int minCut(string s) {
        int n = s.size();
        vector<int> dp(n, -1);
        return minCutHelper(s, 0, dp) - 1;
    }
};
