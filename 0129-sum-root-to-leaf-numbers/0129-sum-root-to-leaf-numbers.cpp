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
    int sum = 0;
    
    void dfs(TreeNode* root, int res) {
        if(!root)   return;
        
        if(!root->left && !root->right)
            // reached to a leaf node
            // include the current node->value and add with sum
            sum += res * 10 + root->val;
        
        // Otherwise include current node->value and
        // explore node->left and node->right
        res = res * 10 + root->val;
        
        dfs(root->left, res);
        dfs(root->right, res);
    }
        
    int sumNumbers(TreeNode* root) {
        dfs(root, 0);
        return sum;
    }
};