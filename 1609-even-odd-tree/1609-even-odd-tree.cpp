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
    bool isEvenOddTree(TreeNode* root) {
        queue<TreeNode*> q;
        TreeNode* curr = root;
        q.push(curr);
        
        bool even = true;
        
        while(!q.empty()) {
            int size = q.size();
            int prev = even ? INT_MIN : INT_MAX;
            
            while(size > 0) {
                curr = q.front();
                q.pop();
                
                if((even && (curr->val % 2 == 0 || curr->val <= prev)) || (!even && (curr->val % 2 == 1 || curr->val >= prev)))
                    return false;
                
                prev = curr->val;
                
                if(curr->left)  q.push(curr->left);
                if(curr->right) q.push(curr->right);
                
                size--;
            }
            
            even = !even;
        }
        
        return true;
    }
};