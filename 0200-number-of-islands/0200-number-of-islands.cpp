class Solution {
public:
    void dfs(int i, int j, vector<vector<char>>& grid, vector<vector<bool>>& visited) {
        // checking boundary
        if(i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size())
            return;
        // if the current location is already visited or contains water
        if(grid[i][j] == '0' || visited[i][j])
            return;
        
        // mark the current as visited
        visited[i][j] = true;
        
        // do the dfs calls for all four directions
        dfs(i+1, j, grid, visited); // down
        dfs(i-1, j, grid, visited); // up
        dfs(i, j+1, grid, visited); // right
        dfs(i, j-1, grid, visited); // left
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        int count = 0;
        
        vector<vector<bool>> visited(row, vector<bool>(col, false));
        
        for(int i=0; i<row; i++) {
            for(int j=0; j<col; j++) {
                if(grid[i][j] == '1' && !visited[i][j]) {
                    dfs(i, j, grid, visited);
                    count++;
                }
            }
        }
        
        return count;
    }
};