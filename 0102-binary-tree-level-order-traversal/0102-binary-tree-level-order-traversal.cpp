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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        
        if(root == nullptr)
            return ans;
        
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty()) {
            vector<int> curr;
            int n = q.size();
            
            for(int i=0; i<n; i++) {
                TreeNode* currNode = q.front();
                q.pop();
                curr.push_back(currNode->val);
            
                if(currNode->left)
                    q.push(currNode->left);
                if(currNode->right)
                    q.push(currNode->right);
            }
            
            ans.push_back(curr);
        }
        
        return ans;
    }
};