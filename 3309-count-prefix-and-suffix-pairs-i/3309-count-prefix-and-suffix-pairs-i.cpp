class Solution {
public:
    int countPrefixSuffixPairs(const std::vector<std::string>& words) {
        int n = words.size();
        int cnt = 0;

        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (isPrefixAndSuffix(words[i], words[j])) {
                    ++cnt;
                }
            }
        }

        return cnt;
    }

private:
    bool isPrefixAndSuffix(const std::string& str1, const std::string& str2) {
        int n1 = str1.length();
        int n2 = str2.length();

        if (n1 > n2) {
            return false; 
        }

        for (int i = 0; i < n1; i++) {
            if (str1[i] != str2[i]) {
                return false;
            }
        }

        for (int i = 0; i < n1; i++) {
            if (str1[i] != str2[n2 - n1 + i]) {
                return false;
            }
        }

        return true;
    }
};
