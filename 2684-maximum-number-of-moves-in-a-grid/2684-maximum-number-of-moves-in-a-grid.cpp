class Solution {
public:
    int maxMoves(vector<vector<int>>& grid) {
        int n =  grid.size();
        int m = grid[0].size();
        queue<vector<int>> q; // vector<int>(3, {row, col, count})
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        vector<int> dirs = {-1, 0, 1};
        
        for(int i=0; i<n; i++) {
            q.push({i, 0, 0});
            visited[i][0] = true;
        }
        
        int maxMoves = 0;
        while(!q.empty()) {
            int size = q.size();
            for(int i=0; i<size; i++) {
                vector<int> front = q.front(); q.pop();
                int row = front[0];
                int col = front[1];
                int moves = front[2];
                maxMoves = max(maxMoves, moves);
                for(int dir : dirs) {
                    int newRow = row + dir;
                    int newCol = col + 1;
                    if(0 <= newRow && newRow < n && 
                       0 <= newCol && newCol < m && 
                       grid[newRow][newCol] > grid[row][col] && 
                       !visited[newRow][newCol]) {
                        visited[newRow][newCol] = true;
                        q.push({newRow, newCol, moves + 1});
                    }
                }
            }
        }
        
        return maxMoves;
    }
};