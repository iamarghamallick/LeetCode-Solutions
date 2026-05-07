class Solution {
    public char[][] rotateTheBox(char[][] grid) {
        int n = grid.length;
        int m = grid[0].length;

        for(int i=0; i<n; i++) {
            int k = m-1;
            for(int j=m-1; j>=0; j--) {
                if(grid[i][j] == '.') continue;
                else if(grid[i][j] == '*') k = j-1;
                else {
                    grid[i][j] = '.';
                    grid[i][k] = '#';
                    k--;
                }
            }
        }

        char[][] ans = new char[m][n];
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                ans[j][i] = grid[i][j];
            }
        }

        for(int i=0; i<m; i++) {
            int left = 0;
            int right = n - 1;

            while(left <= right) {
                char temp = ans[i][left];
                ans[i][left] = ans[i][right];
                ans[i][right] = temp;
                left++;
                right--;
            }
        }

        return ans;
    }
}