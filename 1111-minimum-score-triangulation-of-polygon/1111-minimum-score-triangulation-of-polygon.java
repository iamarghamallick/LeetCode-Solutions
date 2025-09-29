class Solution {
    int[] values;
    int[][] memo;

    public int minScoreTriangulation(int[] values) {
        this.values = values;
        int n = values.length;
        memo = new int[n][n];
        return dp(0, n - 1);
    }

    public int dp(int i, int j) {
        if (j < i + 2)
            return 0;
        if (memo[i][j] != 0)
            return memo[i][j];
        int res = Integer.MAX_VALUE;

        for (int k = i + 1; k < j; k++)
            res = Math.min(res, values[i] * values[k] * values[j] +
                    dp(i, k) + dp(k, j));

        return memo[i][j] = res;
    }
}