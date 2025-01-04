class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int n = s.size();
        unordered_set<char> uniqueLetters(s.begin(), s.end());
        int ans = 0;
        for (auto it : uniqueLetters) {
            int firstOcc = -1;
            int lastOcc = -1;
            for (int i = 0; i < n; i++) {
                if (s[i] == it) {
                    if (firstOcc == -1) {
                        firstOcc = i;
                    }
                    lastOcc = i;
                }
            }
            unordered_set<char> st2;
            for (int i = firstOcc + 1; i < lastOcc; i++) {
                st2.insert(s[i]);
            }
            ans += st2.size();
        }
        return ans;
    }
};