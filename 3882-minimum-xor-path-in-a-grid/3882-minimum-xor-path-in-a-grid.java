class Solution {
    public int minCost(int[][] grid) {
        int n = grid.length;
        int m = grid[0].length;

        int[][][] dp = new int[n][m][1024];

        for (int[][] row2d : dp) {
            for (int[] row1d : row2d) {
                Arrays.fill(row1d, -1);
            }
        }

        return solve(0, 0, 0, grid, dp);
    }

    private int solve(int i, int j, int x, int[][] grid, int[][][] dp) {
        int n = grid.length;
        int m = grid[0].length;

        x ^= grid[i][j];

        if (i == n - 1 && j == m - 1) {
            return x;
        }

        if (dp[i][j][x] != -1) {
            return dp[i][j][x];
        }

        int ans = Integer.MAX_VALUE;

        if (j + 1 < m) {
            ans = Math.min(ans, solve(i, j + 1, x, grid, dp));
        }

        if (i + 1 < n) {
            ans = Math.min(ans, solve(i + 1, j, x, grid, dp));
        }

        return dp[i][j][x] = ans;
    }
}