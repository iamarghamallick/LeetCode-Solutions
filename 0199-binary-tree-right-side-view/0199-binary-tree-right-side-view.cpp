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
    vector<int> ans;
    
    void rightView(TreeNode* root, int level) {
        if(!root)   return;
        
        if(level == ans.size())
            ans.push_back(root->val);
        
        rightView(root->right, 1 + level);
        rightView(root->left, 1 + level);
    }
        
    vector<int> rightSideView(TreeNode* root) {
        rightView(root, 0);
        
        return ans;
    }
};