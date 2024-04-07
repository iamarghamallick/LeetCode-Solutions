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
    int good = 0;
    
    void dfs(TreeNode* root, int maxVal) {
        if(!root)
            return;
        
        if(root->val >= maxVal)
            good++;
        
        dfs(root->left, max(maxVal, root->val));
        dfs(root->right, max(maxVal, root->val));
    }
    
    int goodNodes(TreeNode* root) {
        dfs(root, root->val);
        return good;
    }
};