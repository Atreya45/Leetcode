/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    int helper(TreeNode* root, int& anss) {
        if (!root) {
            return 0;
        }
        int left = max(0, helper(root->left, anss));

        int right = max(0, helper(root->right, anss));

        int temp = root->val + left + right;
        anss = max(anss, temp);
        return root->val + max(left, right);
    }
    int maxPathSum(TreeNode* root) {
        int anss = INT_MIN;
        if (!root) {
            return 0;
        }
        helper(root, anss);
        return anss;
    }
};