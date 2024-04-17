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
    void dfs(TreeNode* root, string curr, string &ans) {
        if(!root)   return;
        
        if(!root->left && !root->right) {
            // reached at leaf node
            curr = char(root->val + 'a') + curr;
            if(ans == "" || curr < ans)
                ans = curr;
        }
        
        dfs(root->left, char(root->val + 'a') + curr, ans);
        dfs(root->right, char(root->val + 'a') + curr, ans);
    }
    
    string smallestFromLeaf(TreeNode* root) {
        string ans = "";
        dfs(root, "", ans);
        return ans;
    }
};