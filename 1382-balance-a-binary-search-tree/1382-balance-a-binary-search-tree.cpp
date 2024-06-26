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
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> arr;
        inorder(root, arr);
        sort(arr.begin(), arr.end());
        
        return createBST(arr, 0, arr.size() - 1);
    }
private:
    void inorder(TreeNode* root, vector<int> &arr) {
        if(!root)   return;
        inorder(root->left, arr);
        arr.push_back(root->val);
        inorder(root->right, arr);
    }
    
    TreeNode* createBST(vector<int> &arr, int start, int end) {
        if(start > end)
            return nullptr;
        
        int mid = start + (end - start) / 2;
        
        TreeNode* left = createBST(arr, start, mid - 1);
        TreeNode* right = createBST(arr, mid + 1, end);
        
        return new TreeNode(arr[mid], left, right);
    }
};