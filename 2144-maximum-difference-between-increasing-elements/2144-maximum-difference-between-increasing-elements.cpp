class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        stack<pair<int, int>> st; 
        int diff = -1;

        for (int i = 0; i < nums.size(); i++) {
            if (st.empty() || nums[i] < st.top().first) {
                st.push({nums[i], i});
            }

            if (!st.empty() && st.top().second < i && nums[i] > st.top().first) {
                diff = max(diff, nums[i] - st.top().first);
            }
        }

        return diff;
    }
};