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
    int count;
    
    int dfs(TreeNode* root) {
        if(!root)
            return 0;
        
        int l = dfs(root->left);
        int r = dfs(root->right);
        
        count += abs(l) + abs(r);
        
        return (root->val - 1) + l + r;
    }
    
    int distributeCoins(TreeNode* root) {
        count = 0;
        dfs(root);
        return count;
    }
};