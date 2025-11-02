class Solution {
    public int countUnguarded(int n, int m, int[][] guards, int[][] walls) {
        // WALL = -1
        // UNGUARDED = 0
        // GUARD = 1
        // GUARDED = 2

        int[][] grid = new int[n][m];
        for(int[] guard: guards) grid[guard[0]][guard[1]] = 1;
        for(int[] wall: walls) grid[wall[0]][wall[1]] = -1;

        for(int[] guard: guards) {
            int r = guard[0];
            int c = guard[1];
            
            // up
            for(int i=r-1; i>=0; i--) {
                if(grid[i][c] == -1 || grid[i][c] == 1) break;
                grid[i][c] = 2;
            }
            // down
            for(int i=r+1; i<n; i++) {
                if(grid[i][c] == -1 || grid[i][c] == 1) break;
                grid[i][c] = 2;
            }
            // left
            for(int i=c-1; i>=0; i--) {
                if(grid[r][i] == -1 || grid[r][i] == 1) break;
                grid[r][i] = 2;
            }
            // right
            for(int i=c+1; i<m; i++) {
                if(grid[r][i] == -1 || grid[r][i] == 1) break;
                grid[r][i] = 2;
            }
        }

        int count = 0;
        for(int i=0; i<n; i++)
            for(int j=0; j<m; j++)
                if(grid[i][j] == 0)
                    count++;

        return count;
    }
}