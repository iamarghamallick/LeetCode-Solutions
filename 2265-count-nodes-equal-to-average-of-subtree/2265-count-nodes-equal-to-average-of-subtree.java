/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {

    int count;

    public int averageOfSubtree(TreeNode root) {
        count = 0;
        solve(new int[2], root);
        return count;
    }

    private int[] solve(int[] res, TreeNode root) {
        if (root == null) {
            return new int[] { 0, 0 };
        }

        int[] left = solve(res, root.left);
        int[] right = solve(res, root.right);

        int n = 1 + left[0] + right[0];
        int sum = root.val + left[1] + right[1];

        if ((sum / n) == root.val) {
            count++;
        }

        return new int[] { n, sum };
    }
}