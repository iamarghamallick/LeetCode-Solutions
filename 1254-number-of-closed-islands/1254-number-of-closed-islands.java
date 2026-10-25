class Solution {
    public int closedIsland(int[][] grid) {
        int n = grid.length;
        int m = grid[0].length;

        boolean[][] visited = new boolean[n][m];

        int count = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 0 && !visited[i][j]) {
                    count += bfs(i, j, grid, visited);
                }
            }
        }

        return count;
    }

    private int bfs(int i, int j, int[][] grid, boolean[][] visited) {
        int n = grid.length;
        int m = grid[0].length;

        boolean isClosed = true;

        int[][] dirs = new int[][] {
                { 0, 1 }, { 0, -1 }, { 1, 0 }, { -1, 0 }
        };

        Queue<int[]> q = new LinkedList<>();

        q.offer(new int[] { i, j });
        visited[i][j] = true;

        while (!q.isEmpty()) {
            int[] temp = q.poll();
            int x = temp[0];
            int y = temp[1];

            if (x == 0 || y == 0 || x == n - 1 || y == m - 1) {
                isClosed = false;
            }

            for (int[] dir : dirs) {
                int nx = x + dir[0];
                int ny = y + dir[1];

                if (0 <= nx && nx < n && 0 <= ny && ny < m && grid[nx][ny] == 0 && !visited[nx][ny]) {
                    visited[nx][ny] = true;
                    q.offer(new int[] { nx, ny });
                }
            }
        }

        return isClosed ? 1 : 0;
    }
}