class Solution {
public:
    // vector<int> dp;

    // bool wordBreakHelper(unordered_set<string>& st, int idx, string &s, int
    // &n) {
    //     if (idx >= n) {
    //         return true;
    //     }

    //     if (dp[idx] != -1)
    //         return dp[idx];
    //     if (st.find(s.substr(idx,n-idx)) != st.end()){
    //         return true;
    //     }
    //     for (int i = 1; i+idx <= n; i++) {
    //         string temp = s.substr(idx, i);
    //         if (st.find(temp) != st.end() &&
    //             wordBreakHelper(st, idx + i, s, n)) {
    //             return dp[idx] = true;
    //         }
    //     }

    //     return dp[idx] = false;
    // }

    // bool wordBreak(string s, vector<string>& wordDict) {
    //     unordered_set<string> st(wordDict.begin(), wordDict.end());
    //     int n = s.size();

    //     dp.assign(n+1, -1);

    //     return wordBreakHelper(st, 0, s, n);
    // }
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        unordered_set<string> st(wordDict.begin(), wordDict.end());
        vector<bool> dp(n + 1, false);
        dp[n] = true;
        for (int j = n - 1; j >= 0; j--) {
            for (int i = 1; i + j <= n; i++) {
                string temp = s.substr(j, i);
                if (st.find(temp) != st.end() && dp[j + i]) {
                    dp[j] = true;
                }
            }
        }
        return dp[0];
    }
};