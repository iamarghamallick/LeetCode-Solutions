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
    void dfs(TreeNode* root, int level, unordered_map<int, long long> &map) {
        if(!root) return;
        map[level] += root->val;
        dfs(root->left, level + 1, map);
        dfs(root->right, level + 1, map);
    }
    
    long long kthLargestLevelSum(TreeNode* root, int k) {
        unordered_map<int, long long> map;
        dfs(root, 0, map);
        if(k-1 >= map.size()) return -1;
        vector<long long> arr(map.size());
        for(auto &[key, val] : map) arr[key] = val;
        sort(arr.begin(), arr.end());
        return arr[arr.size() - k];
    }
};