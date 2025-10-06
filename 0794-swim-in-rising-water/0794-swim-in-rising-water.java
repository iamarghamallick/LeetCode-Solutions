class Solution {
    public int swimInWater(int[][] grid) {
        int n = grid.length;
        int l = grid[0][0];
        int r = n * n - 1;
        int ans = 0;

        while (l <= r) {
            int mid = l + (r - l) / 2;
            boolean[][] visited = new boolean[n][n];

            if (possibleToReach(0, 0, grid, mid, visited)) {
                ans = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }

        return ans;
    }

    private boolean possibleToReach(int x, int y, int[][] grid, int t, boolean[][] visited) {
        int n = grid.length;

        if (x < 0 || x >= n || y < 0 || y >= n || visited[x][y] || grid[x][y] > t)
            return false;

        visited[x][y] = true;

        if (x == n - 1 && y == n - 1)
            return true;

        int[][] dirs = { { -1, 0 }, { 0, -1 }, { 1, 0 }, { 0, 1 } };

        for (int[] dir : dirs) {
            int newX = x + dir[0];
            int newY = y + dir[1];

            if (possibleToReach(newX, newY, grid, t, visited))
                return true;
        }

        return false;
    }
}