class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        
        int count = 0;
        
        for(int i=0; i<row; i++) {
            for(int j=0; j<col; j++) {
                if(grid[i][j] == 1) {
                    // initially add all four directions as boundary
                    count += 4;
                    // four directions, to check
                    // if it is a land, subdtract count by 1
                    if(i-1 >= 0 && grid[i-1][j] == 1)
                        count--;
                    if(i+1 < row && grid[i+1][j] == 1)
                        count--;
                    if(j-1 >= 0 && grid[i][j-1] == 1)
                        count--;
                    if(j+1 < col && grid[i][j+1] == 1)
                        count--;
                }
            }
        }
        
        return count;
    }
};