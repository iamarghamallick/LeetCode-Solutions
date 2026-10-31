class Solution {

    private static final int mod = 1000000007;

    public int uniquePaths(int[][] grid) {
        int n = grid.length;
        int m = grid[0].length;

        int[][][] dp = new int[n][m][2];

        for (int[][] row : dp) {
            for (int[] cell : row) {
                Arrays.fill(cell, -1);
            }
        }

        return solve(0, 0, 0, grid, dp);
    }

    private int solve(int i, int j, int dir, int[][] grid, int[][][] dp) {
        int n = grid.length;
        int m = grid[0].length;

        if (i == n - 1 && j == m - 1) {
            return 1;
        }

        if (i >= n || j >= m) {
            return 0;
        }

        if (dp[i][j][dir] != -1) {
            return dp[i][j][dir];
        }

        if (grid[i][j] == 1) {
            if (dir == 0) {
                return dp[i][j][dir] = solve(i + 1, j, 1, grid, dp);
            }

            return dp[i][j][dir] = solve(i, j + 1, 0, grid, dp);
        }

        return dp[i][j][dir] = (solve(i + 1, j, 1, grid, dp) + solve(i, j + 1, 0, grid, dp)) % mod;
    }
}