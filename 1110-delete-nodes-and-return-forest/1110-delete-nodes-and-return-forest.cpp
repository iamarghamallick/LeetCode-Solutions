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
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        unordered_set<int> set(to_delete.begin(), to_delete.end());
        vector<TreeNode*> ans;
        
        root = helper(root, set, ans);
        if(root)    ans.push_back(root);
        
        return ans;
    }
    
private:
    TreeNode* helper(TreeNode* root, unordered_set<int> &set, vector<TreeNode*> &ans) {
        if(!root)
            return nullptr;
        
        root->left = helper(root->left, set, ans);
        root->right = helper(root->right, set, ans);
        
        if(set.find(root->val) != set.end()) {
            if(root->left)  ans.push_back(root->left);
            if(root->right) ans.push_back(root->right);
            delete root;
            return nullptr;
        }
        
        return root;
    }
};