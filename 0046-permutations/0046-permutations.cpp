class Solution {
private:
    void permuteHelper(vector<int>& nums, vector<int>& temp,
                       vector<vector<int>>& ans, set<int>& st) {
        if (temp.size() == nums.size()) {
            ans.push_back(temp);
            return;
        }
        for (int index = 0; index < nums.size(); index++) {
            if (st.find(nums[index]) == st.end()) {
                st.insert(nums[index]);
                temp.push_back(nums[index]);
                permuteHelper(nums, temp, ans,st);
                temp.pop_back();
                st.erase(nums[index]);
            }
        }
    }

public:
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        vector<int> temp;
        set<int> st;
        permuteHelper(nums, temp, ans, st);
        return ans;
    }
};