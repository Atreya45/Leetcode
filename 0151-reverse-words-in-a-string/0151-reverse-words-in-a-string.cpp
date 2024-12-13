class Solution {
public:
    string reverseWords(string s) {
        stringstream ss(s);
        string token = "";
        vector<string> temp;
        while (getline(ss, token, ' ')) {
            if (!token.empty()) {
                temp.push_back(token);
            }
        }
        reverse(temp.begin(), temp.end());
        string ans;
        for (int i = 0; i < temp.size() - 1; i++) {
            ans += temp[i];
            ans += " ";
        }
        ans += temp[temp.size() - 1];
        return ans;
    }
};