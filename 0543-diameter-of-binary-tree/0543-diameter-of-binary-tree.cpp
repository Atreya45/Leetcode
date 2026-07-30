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
    int maxDepth(TreeNode* root,int &ans) {
        if(root==NULL){return  0;}
        int left  = maxDepth(root->left,ans);
        int right  = maxDepth(root->right,ans);
        int maxi = max(left,right);
        ans=max(ans,left+right);
        return maxi+1;
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        if(!root){
            return 0;
        }
        int ans=0;
        maxDepth(root,ans);
        return ans;
    }
};