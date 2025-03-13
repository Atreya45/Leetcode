class Solution {
public:
    string kNextPermutation(string num, int kValue) {
        int n = num.size(), k, l;
        while (kValue--) {
            for (k = n - 2; k >= 0; k--) {
                if (num[k] < num[k + 1]) {
                    break;
                }
            }
            for (l = n - 1; l > k; l--) {
                if (num[l] > num[k]) {
                    break;
                }
            }
            swap(num[l], num[k]);
            reverse(num.begin() + k + 1, num.end());
        }
        return num;
    }
    int getMinSwaps(string num, int k) {
        string test = num;
        string target = kNextPermutation(test, k);
        cout << target << " ";
        int swaps = 0, n = num.size();

        for (int i = 0; i < n; i++) {
            if (num[i] == target[i])
                continue; 
            int j = i;
            while (num[j] != target[i])
                j++;
            while (j > i) {
                swap(num[j], num[j - 1]);
                swaps++;
                j--;
            }
        }
        return swaps;
    }
};