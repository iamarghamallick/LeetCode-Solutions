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
    vector<int> leaf1;
    vector<int> leaf2;
    
    void travarse(TreeNode* root, int flag) {
        if(!root)   return;
        if(!root->left && !root->right) {
            if(flag == 1)   leaf1.push_back(root->val);
            if(flag == 2)   leaf2.push_back(root->val);
        }
        travarse(root->left, flag);
        travarse(root->right, flag);
    }
    
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        travarse(root1, 1);
        travarse(root2, 2);
        
        if(leaf1.size() != leaf2.size())    return false;
        for(int i=0; i<leaf1.size(); i++) {
            if(leaf1[i] != leaf2[i])    return false;
        }
        
        return true;
    }
};