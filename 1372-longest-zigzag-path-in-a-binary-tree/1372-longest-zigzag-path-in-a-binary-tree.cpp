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
    int ans = 0;
    
    void dfs(TreeNode* root, string dir, int count) {
        if(!root)   return;
        
        ans = max(ans, count);
        
        if(dir == "left") {
            dfs(root->left, "right", count + 1);
            dfs(root->right, "left", 1);
        } else {
            dfs(root->right, "left", count + 1);
            dfs(root->left, "right", 1);
        }
    }
    
    int longestZigZag(TreeNode* root) {
        dfs(root, "left", 0);
        dfs(root, "right", 0);
        
        return ans;
    }
};