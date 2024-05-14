class Solution {
private:
    int solve(int i, int j, vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        
        if(i < 0 || j < 0 || i == row || j == col || grid[i][j] == 0)
            return 0;
        
        int maxGold = 0;
        
        // Mark the cell as visited and save the value
        int orgVal = grid[i][j];
        grid[i][j] = 0;
        
        // Backtrack in each of the four directions
        maxGold = max(maxGold, solve(i-1, j, grid)); // up
        maxGold = max(maxGold, solve(i+1, j, grid)); // down
        maxGold = max(maxGold, solve(i, j-1, grid)); // left
        maxGold = max(maxGold, solve(i, j+1, grid)); // right
        
        // Set the cell back to its original value
        grid[i][j] = orgVal;
        
        return orgVal + maxGold;
    }
    
public:
    int getMaximumGold(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        int maxGold = 0;
        
        for(int i=0; i<row; i++)
            for(int j=0; j<col; j++)
                maxGold = max(maxGold, solve(i, j, grid));
        
        return maxGold;
    }
};