class Solution {
public:
    int rec(vector<int>& nums, int target, int sum, int i, vector<vector<int>>& dp, int offset) {
        if (i == nums.size()) {
            return sum == target ? 1 : 0;
        }
        if (dp[sum + offset][i] != -1) {
            return dp[sum + offset][i];
        }
        int add = rec(nums, target, sum + nums[i], i + 1, dp, offset);
        int subtract = rec(nums, target, sum - nums[i], i + 1, dp, offset);
        dp[sum + offset][i] = add + subtract;
        return dp[sum + offset][i];
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        int offset = sum; // Offset to handle negative indices
        vector<vector<int>> dp(2 * sum + 1, vector<int>(nums.size(), -1));
        return rec(nums, target, 0, 0, dp, offset);
    }
};
