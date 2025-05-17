class Solution {
    void generateParenthesisHelper(vector<string>& result, string& temp, int n, int count) {
        if (count < 0) return;

        if (temp.size() == 2 * n) {
            if (count == 0) result.push_back(temp);
            return;
        }

        temp.push_back('(');
        generateParenthesisHelper(result, temp, n, count + 1);
        temp.pop_back();

        temp.push_back(')');
        generateParenthesisHelper(result, temp, n, count - 1);
        temp.pop_back();
    }

public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        string temp = "(";
        generateParenthesisHelper(result, temp, n, 1);
        return result;
    }
};
