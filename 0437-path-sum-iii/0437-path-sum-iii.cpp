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
    long long helper(struct TreeNode* root, int targetSum, long long sum) {
        if(!root)   return 0;

        sum += root->val;
        long long left_count = helper(root->left, targetSum, sum);
        long long right_count = helper(root->right, targetSum, sum);

        return sum == targetSum ? 1 + left_count + right_count : left_count + right_count;
    }
    
    int pathSum(TreeNode* root, int targetSum) {
        long long sum = 0;

        if(!root)   return 0;


        long long count = helper(root, targetSum, sum);
        long long left_count = pathSum(root->left, targetSum);
        long long right_count = pathSum(root->right, targetSum);

        return count + left_count + right_count;
    }
};