class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        int minI = n-1, minJ = m-1;
        int maxI = 0, maxJ = 0;

        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(grid[i][j] == 1) {
                    minI = min(minI, i);
                    minJ = min(minJ, j);
                    maxI = max(maxI, i);
                    maxJ = max(maxJ, j);
                }
            }
        }

        return (maxI - minI + 1) * (maxJ - minJ + 1);
    }
};