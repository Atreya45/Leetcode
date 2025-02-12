class Solution {
public:
    int digitSum(int x) {
        int s = 0;
        while (x) {
            s += x % 10;
            x /= 10;
        }
        return s;
    }

    int maximumSum(vector<int>& nums) {
        int n = nums.size();
        vector<int> sum;
        map<int, vector<int>> mp;
        for (int i = 0; i < n; i++) {
            int val = digitSum(nums[i]);
            mp[val].push_back(nums[i]);
        }
        int ans = -1;
        for (auto it : mp) {
            if (it.second.size() > 1) {
                sort(it.second.rbegin(), it.second.rend());
                ans = max(ans, it.second[0] + it.second[1]);
            }
        }
        return ans;
    }
};