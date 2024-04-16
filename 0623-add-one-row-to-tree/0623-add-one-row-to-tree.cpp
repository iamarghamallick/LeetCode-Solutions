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
    void dfs(TreeNode* root, int val, int depth, int curr) {
        if(!root)   return;
        
        if(depth == curr) {
            TreeNode* tempLeft = root->left;
            TreeNode* tempRight = root->right;
            
            root->left = new TreeNode(val);
            root->right = new TreeNode(val);
            
            root->left->left = tempLeft;
            root->right->right = tempRight;
            
            return;
        }
        
        dfs(root->left, val, depth, curr + 1);
        dfs(root->right, val, depth, curr + 1);
    }
    
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth == 1)
            return new TreeNode(val, root, nullptr);
            
        dfs(root, val, depth - 1, 1);
        
        return root;
    }
};