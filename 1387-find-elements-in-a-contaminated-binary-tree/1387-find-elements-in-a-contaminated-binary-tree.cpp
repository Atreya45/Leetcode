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
class FindElements {
public:
    map<int,int>values;
    void recoverTree(TreeNode* root){
        if(root){
            values[root->val]=1;
            if(root->left){
                root->left->val=2*root->val+1;
                recoverTree(root->left);
            }
            if(root->right){
                root->right->val=2*root->val+2;
                recoverTree(root->right);
            }
        }
    }
    FindElements(TreeNode* root) {
        if(root){
            root->val=0;
        }
        recoverTree(root);
    }
    
    bool find(int target) {
        if(values[target]){
            return true;
        }
        return false;
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */