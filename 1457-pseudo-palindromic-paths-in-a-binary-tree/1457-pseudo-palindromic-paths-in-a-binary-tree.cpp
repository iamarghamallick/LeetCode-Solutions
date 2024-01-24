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
    int count = 0;
    
    void preOrder(TreeNode* node, int path) {
        if(node) {
            path ^= (1 << node->val);
            if(!node->left && !node->right)
                if((path & (path-1)) == 0)
                    ++count;
            preOrder(node->left, path);
            preOrder(node->right, path);
        }
    }
    
    int pseudoPalindromicPaths (TreeNode* root) {
        preOrder(root, 0);
        return count;
    }
};