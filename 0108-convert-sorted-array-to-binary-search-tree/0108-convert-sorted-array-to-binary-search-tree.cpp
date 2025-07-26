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
    TreeNode* toBST(int left, int right, vector<int> &nums) {
        if(left > right) return nullptr;
        int mid = (left + right) / 2;
        TreeNode* node = new TreeNode(nums[mid]);
        node->left = toBST(left, mid-1, nums);
        node->right = toBST(mid+1, right, nums);
        return node;
    }

    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return toBST(0, nums.size()-1, nums);
    }
};