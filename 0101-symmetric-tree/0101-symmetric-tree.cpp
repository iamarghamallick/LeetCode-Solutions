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
    bool isMirror(TreeNode* l, TreeNode* r) {
        if(!l && !r)    return true;
        if(!l || !r)    return false;
        if(l->val == r->val) return isMirror(l->left, r->right) && isMirror(l->right, r->left);
        return false;
    }
    
    bool isSymmetric(TreeNode* root) {
        if(root == nullptr)     return true;
        return isMirror(root->left, root->right);
    }
};