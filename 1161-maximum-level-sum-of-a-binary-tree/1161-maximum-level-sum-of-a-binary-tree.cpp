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
    unordered_map<int, int> map;
    
    void dfs(TreeNode* root, int level) {
        if(!root)   return;
        
        map[level] += root->val;
        
        dfs(root->left, 1 + level);
        dfs(root->right, 1 + level);
    }
    
    int maxLevelSum(TreeNode* root) {
        dfs(root, 1);
        int sum = INT_MIN;
        int ans = 0;
        
        for(auto i = map.begin(); i != map.end(); i++) {
            if(i->second > sum) {
                sum = i->second;
                ans = i->first;
            } else if(i->second == sum) {
                ans = min(ans, i->first);
            }
        }
        
        return ans;
    }
};