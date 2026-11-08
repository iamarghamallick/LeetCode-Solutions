class Solution {
    public int countServers(int[][] grid) {
        int n = grid.length;
        int m = grid[0].length;

        int[] row = new int[n];
        int[] col = new int[m];

        for (int i = 0; i < n; i++) {
            int count = 0;
            for (int j = 0; j < m; j++) {
                count += grid[i][j] == 1 ? 1 : 0;
            }
            row[i] = count;
        }

        for (int j = 0; j < m; j++) {
            int count = 0;
            for (int i = 0; i < n; i++) {
                count += grid[i][j] == 1 ? 1 : 0;
            }
            col[j] = count;
        }

        int ans = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                ans += grid[i][j] == 1 && (row[i] > 1 || col[j] > 1) ? 1 : 0;
            }
        }

        return ans;
    }
}