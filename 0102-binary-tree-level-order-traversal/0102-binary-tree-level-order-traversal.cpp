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
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>>answer;
        if(!root){
            return answer;
        }
        queue<TreeNode*>q;
        
        q.push(root);
        while(!q.empty()){
            int size=q.size();
            vector<int>curLevel;

            for(int i=0;i<size;i++){
                TreeNode* topElement=q.front();
                q.pop();
                if(topElement->left){
                    q.push(topElement->left);
                }
                if(topElement->right){
                    q.push(topElement->right);
                }
                curLevel.push_back(topElement->val);
            }
            answer.push_back(curLevel);
        }
        return answer;
    }
};