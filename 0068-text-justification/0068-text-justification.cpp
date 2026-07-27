class Solution {
public:
    string findLine(int i, int j, int equalSpaces, int extraSpaces,
                    vector<string>& words, int maxWidth) {
        string line;
        for (int k = i; k < j; k++) {
            line += words[k];
            if (k == j - 1) {
                continue;
            }
            for (int z = 0; z < equalSpaces; z++) {
                line += " ";
            }
            if (extraSpaces > 0) {
                line += " ";
                extraSpaces--;
            }
        }
        while (line.size() < maxWidth) {
            line += " ";
        }
        return line;
    }

    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        int n = words.size();
        int i = 0;
        vector<string> ans;
        while (i < n) {
            int j = i + 1;
            int letterCount = words[i].size();
            int spaces = 0;
            while (j < n &&
                   words[j].size() + 1 + letterCount + spaces <= maxWidth) {
                letterCount += words[j].size();
                spaces++;
                j++;
            }
            int remainingSpaces = maxWidth - letterCount;
            int equalSpaces =
                j - i - 1 == 0 ? 0 : remainingSpaces / (j - i - 1);
            int extraSpaces =
                j - i - 1 == 0 ? 0 : remainingSpaces % (j - i - 1);
            if (j == n) {
                equalSpaces = 1;
                extraSpaces = 0;
            }
            ans.push_back(
                findLine(i, j, equalSpaces, extraSpaces, words, maxWidth));
            i = j;
        }
        return ans;
    }
};