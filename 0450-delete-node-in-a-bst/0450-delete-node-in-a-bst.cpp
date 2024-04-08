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
        
        if(!root->left && !root->right && root->val == key)
            return nullptr;
        
        if(key < root->val) 
            // try to delete from left subtree, if found
            root->left = deleteNode(root->left, key);
        
        else if(key > root->val)
            // try to delete from right subtree, if found
            root->right = deleteNode(root->right, key);
        
        else {
            // found the key to be deleted
            
            // 2 cases arises
            // case 1 : check if any one of its left or right node is null,
            //          replace with not null node
            if(!root->left) {
                TreeNode* temp = root->right;
                // free(root);
                return temp;
            } else if(!root->right) {
                TreeNode* temp = root->left;
                // free(root);
                return temp;
            }
            
            // case 2 : both left and right node exist,
            //          -> find Inorder Predecessor
            //          -> replace the value
            //          -> recursively delete the Inorder Predecessor
            
            TreeNode* iPre = inorderPredecessor(root);
            root->val = iPre->val;
            root->left = deleteNode(root->left, iPre->val);
        }
        
        return root;
    }
};