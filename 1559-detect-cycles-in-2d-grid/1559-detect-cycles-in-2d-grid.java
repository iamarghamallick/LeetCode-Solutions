class Solution {
    public boolean containsCycle(char[][] grid) {
        int n = grid.length;
        int m = grid[0].length;
        boolean[][] visited = new boolean[n][m];
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(!visited[i][j]) {
                    if(bfs(i, j, grid, visited)) {
                        return true;
                    }
                }
            }
        }
        return false;
    }

    private boolean bfs(int i, int j, char[][] grid, boolean[][] visited) {
        int n = grid.length;
        int m = grid[0].length;

        LinkedList<int[]> q = new LinkedList<>();
        q.add(new int[] {i, j, -1, -1});
        char c = grid[i][j];

        while(!q.isEmpty()) {
            int[] p = q.remove();
            
            int currI = p[0];
            int currJ = p[1];
            int parentI = p[2];
            int parentJ = p[3];

            if(visited[currI][currJ]) {
                return true;
            }

            visited[currI][currJ] = true;

            // up
            int childI = currI - 1;
            int childJ = currJ;
            if(childI >= 0 && grid[childI][childJ] == c && !(childI == parentI && childJ == parentJ)) {
                q.add(new int[] {childI, childJ, currI, currJ});
            }

            // down
            childI = currI + 1;
            childJ = currJ;
            if(childI < n && grid[childI][childJ] == c && !(childI == parentI && childJ == parentJ)) {
                q.add(new int[] {childI, childJ, currI, currJ});
            }

            // left
            childI = currI;
            childJ = currJ - 1;
            if(childJ >= 0 && grid[childI][childJ] == c && !(childI == parentI && childJ == parentJ)) {
                q.add(new int[] {childI, childJ, currI, currJ});
            }

            // right
            childI = currI;
            childJ = currJ + 1;
            if(childJ < m && grid[childI][childJ] == c && !(childI == parentI && childJ == parentJ)) {
                q.add(new int[] {childI, childJ, currI, currJ});
            }
        }

        return false;
    }
}