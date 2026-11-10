class Solution {
    public int climbStairs(int n, int[] costs) {
        int[] dp = new int[n + 1];
        Arrays.fill(dp, -1);
        return solve(0, n, costs, dp);
    }

    private int solve(int i, int n, int[] costs, int[] dp) {
        if (i == n) {
            return 0;
        }

        if (dp[i] != -1) {
            return dp[i];
        }

        int jump1 = Integer.MAX_VALUE;
        int jump2 = Integer.MAX_VALUE;
        int jump3 = Integer.MAX_VALUE;

        if (i + 1 <= n) {
            jump1 = costs[i + 1 - 1] + 1 + solve(i + 1, n, costs, dp);
        }

        if (i + 2 <= n) {
            jump2 = costs[i + 2 - 1] + 4 + solve(i + 2, n, costs, dp);
        }

        if (i + 3 <= n) {
            jump3 = costs[i + 3 - 1] + 9 + solve(i + 3, n, costs, dp);
        }

        return dp[i] = Math.min(jump1, Math.min(jump2, jump3));
    }
}