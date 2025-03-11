class Solution {
public:
    void permuteHelper(vector<int>& nums, vector<vector<int>>& ans, int index) {
        if (index == nums.size()) {
            ans.push_back(nums);
            return;
        }
        unordered_set<int> used;
        for (int i = index; i < nums.size(); i++) {
            if (used.find(nums[i]) != used.end()) continue;
            used.insert(nums[i]);
            swap(nums[i], nums[index]);
            permuteHelper(nums, ans, index + 1);
            swap(nums[i], nums[index]);
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        permuteHelper(nums, ans, 0);
        return ans;
    }
};
