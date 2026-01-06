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
    public int maxLevelSum(TreeNode root) {
        HashMap<Integer, Integer> map = new HashMap<>();
        dfs(root, map, 1);
        int maxVal = Integer.MIN_VALUE;
        int ans = 0;

        for (Map.Entry<Integer, Integer> entry : map.entrySet()) {
            if(entry.getValue() > maxVal) {
                maxVal = entry.getValue();
                ans = entry.getKey();    
            }
        }

        return ans;
    }

    private void dfs(TreeNode root, HashMap<Integer, Integer> map, int level) {
        if (root == null)
            return;
        map.put(level, map.getOrDefault(level, 0) + root.val);
        dfs(root.left, map, level + 1);
        dfs(root.right, map, level + 1);
    }
}