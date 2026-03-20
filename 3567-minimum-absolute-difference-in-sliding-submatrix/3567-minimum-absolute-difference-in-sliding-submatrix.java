class Solution {
    public int[][] minAbsDiff(int[][] grid, int k) {
        int m = grid.length;
        int n = grid[0].length;
        int[][] ans = new int[m-k+1][n-k+1];
        for(int i=0; i+k<=m; i++) {
            for(int j=0; j+k<=n; j++) {
                List<Integer> temp = new ArrayList<>();
                for(int r=i; r<i+k; r++) {
                    for(int c=j; c<j+k; c++) {
                        temp.add(grid[r][c]);
                    }
                }
                int min = Integer.MAX_VALUE;
                Collections.sort(temp);
                for(int t=1; t<temp.size(); t++) {
                    if(temp.get(t).equals(temp.get(t-1))) {
                        continue;
                    }
                    min = Math.min(min, temp.get(t) - temp.get(t-1));
                }
                if(min != Integer.MAX_VALUE) {
                    ans[i][j] = min;
                }
            }
        }
        return ans;
    }
}