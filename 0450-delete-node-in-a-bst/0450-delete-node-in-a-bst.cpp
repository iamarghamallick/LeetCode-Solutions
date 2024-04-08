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
    TreeNode* inorderPredecessor(TreeNode* node) {
        // right-most leaf node of the left sub-tree
        // it is given that both left and right node exist for this node
        TreeNode* iPre = node->left;
        
        while(iPre->right)
            iPre = iPre->right;
        
        return iPre;
    }
    
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root)
            return nullptr;
        
        if(!root->left && !root->right && root->val == key) {
            // free(root);
            return nullptr;
        }
        
        if(key < root->val) 
            root->left = deleteNode(root->left, key);
        
        else if(key > root->val)
            root->right = deleteNode(root->right, key);
        
        else {
            if(!root->left) {
                TreeNode* temp = root->right;
                // free(root);
                return temp;
            } else if(!root->right) {
                TreeNode* temp = root->left;
                // free(root);
                return temp;
            }
            
            TreeNode* iPre = inorderPredecessor(root);
            root->val = iPre->val;
            root->left = deleteNode(root->left, iPre->val);
        }
        
        return root;
    }
};