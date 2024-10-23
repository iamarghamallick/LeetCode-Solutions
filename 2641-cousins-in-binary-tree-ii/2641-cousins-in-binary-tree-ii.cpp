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
    int map[100000];
    
    void dfs1(TreeNode* root, int level) {
        if(!root)   return;
        
        map[level] += root->val;
        
        dfs1(root->left, level + 1);
        dfs1(root->right, level + 1);
    }
    
    void dfs2(TreeNode* root, int level, int siblingSum) {
        if(!root)   return;
        
        int left = root->left == nullptr ? 0 : root->left->val;
        int right = root->right == nullptr ? 0 : root->right->val;
        
        if(level == 0 || level == 1)
            root->val = 0;
        else 
            root->val = map[level] - root->val - siblingSum;
        
        dfs2(root->left, level + 1, right);
        dfs2(root->right, level + 1, left);
    }
    
    TreeNode* replaceValueInTree(TreeNode* root) {
        dfs1(root, 0);
        dfs2(root, 0, 0);
        
        return root;
    }
};