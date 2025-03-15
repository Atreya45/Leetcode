class Solution {
public:
    string nextPerm(string &s, int k, int n) {
        int kk, l;
        while (k--) {
            for (kk = n - 2; kk >= 0; kk--) {
                if (s[kk] < s[kk + 1]) {
                    break;
                }
            }
            for (l = n - 1; l > kk; l--) {
                if (s[l] > s[kk]) {

                    break;
                }
            }
            swap(s[kk],s[l]);
            reverse(s.begin()+kk+1,s.end());
        }
        return s;
    }
    string getPermutation(int n, int k) {
        string s = "";
        for (int i = 0; i < n; i++) {
            s += to_string(i + 1);
        }
        cout<<s<<" ";
        if(k==1){
            return s;
        }
        string ans = nextPerm(s, k-1, n);
        return ans;
    }
};