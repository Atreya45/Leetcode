/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    int findHeight(TreeNode* root){
        if(!root){
            return 0;
        }
        return max(findHeight(root->left),findHeight(root->right))+1;
    }
public:
    bool isBalanced(TreeNode* root) {
        if(!root){
            return true;
        }
        int left=findHeight(root->left);
        int right=findHeight(root->right);
        if(abs(left-right)>1){
            return false;
        }
        return isBalanced(root->left)&&isBalanced(root->right);
    }
};