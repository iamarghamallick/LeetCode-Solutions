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
    void inOrder(TreeNode* root, unordered_map<int, int>& counter) {
        if(root == NULL)
            return;
        
        counter[root->val]++;
        inOrder(root->left, counter);
        inOrder(root->right, counter);
    }

    vector<int> findMode(TreeNode* root) {
        unordered_map<int, int> counter;
        inOrder(root, counter);
        int maxFreq = 0;

        for(auto& [key, val] : counter)
            maxFreq = max(maxFreq, val);

        vector<int> ans;
        for(auto& [key, val] : counter) {
            if(val == maxFreq)
                ans.push_back(key);
        }

        return ans;
    }
};