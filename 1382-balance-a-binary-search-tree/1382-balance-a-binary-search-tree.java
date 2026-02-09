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
    public TreeNode balanceBST(TreeNode root) {
        ArrayList<Integer> arr = new ArrayList<>();
        inorder(root, arr);
        return buildTree(0, arr.size() - 1, arr);
    }

    private void inorder(TreeNode root, ArrayList<Integer> arr) {
        if(root == null) return;
        inorder(root.left, arr);
        arr.add(root.val);
        inorder(root.right, arr);
    }

    private TreeNode buildTree(int left, int right, ArrayList<Integer> arr) {
        if(left > right) return null;
        int mid = (left + right) / 2;
        TreeNode node = new TreeNode(arr.get(mid));
        node.left = buildTree(left, mid-1, arr);
        node.right = buildTree(mid+1, right, arr);
        return node;
    }
}