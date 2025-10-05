class Solution {
    public List<List<Integer>> pacificAtlantic(int[][] heights) {
        int rows = heights.length;
        int cols = heights[0].length;

        boolean[][] pacificVisited = new boolean[rows][cols];
        boolean[][] atlanticVisited = new boolean[rows][cols];

        for(int i=0; i<rows; i++) {
            dfs(i, 0, pacificVisited, heights);
            dfs(i, cols - 1, atlanticVisited, heights);
        }

        for(int i=0; i<cols; i++) {
            dfs(0, i, pacificVisited, heights);
            dfs(rows - 1, i, atlanticVisited, heights);
        }

        List<List<Integer>> ans = new ArrayList<>();

        for(int i=0; i<rows; i++) 
            for(int j=0; j<cols; j++) 
                if(pacificVisited[i][j] && atlanticVisited[i][j]) 
                    ans.add(Arrays.asList(i, j));

        return ans;
    }

    private void dfs(int x, int y, boolean[][] visited, int[][] heights) {
        int rows = heights.length;
        int cols = heights[0].length;

        visited[x][y] = true;

        int[][] dirs = { {-1, 0}, {0, -1}, {1, 0}, {0, 1} };

        for(int[] dir : dirs)  {
            int newX = x + dir[0];
            int newY = y + dir[1];
            
            if(isValid(newX, newY, rows, cols) && !visited[newX][newY] && heights[newX][newY] >= heights[x][y])
                dfs(newX, newY, visited, heights);
        }
    }

    private boolean isValid(int x, int y, int rows, int cols) {
        return 0 <= x && x < rows && 0 <= y && y < cols;
    }
}