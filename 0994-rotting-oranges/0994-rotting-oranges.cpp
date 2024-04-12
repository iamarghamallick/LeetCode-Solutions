class Solution {
public:
    vector<vector<int>> directions {{0, 1}, {0, -1}, {1, 0}, {-1, 0}}; // allowed directions to go : [[right], [left], [down], [up]]
    
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        queue<pair<pair<int, int>, int>> q; // {{i, j}, time}
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(grid[i][j] == 2) { // i.e., initially rotten
                    q.push({ { i, j }, 0 }); // push with time = 0
                    grid[i][j] = 2; // mark as visited
                }
            }
        }
        
        int time = 0;
        
        while(!q.empty()) {
            pair<pair<int, int>, int> temp = q.front(); q.pop();
            
            int i = temp.first.first;
            int j = temp.first.second;
            int t = temp.second;
            
            time = max(time, t); // update the time
            
            for(auto& dir : directions) {
                int new_i = i + dir[0];
                int new_j = j + dir[1];
                
                // check if this loacation remains inside the grid
                // and it has a fresh orange
                if((new_i >= 0 && new_i < m && new_j >= 0 && new_j < n) && grid[new_i][new_j] == 1) {
                    q.push({ { new_i, new_j }, t + 1 }); // push with time = t + 1
                    grid[new_i][new_j] = 2; // mark as visited
                }
            }
        }
        
        // if still we find a fresh orange
        // return -1
        for(int i=0; i<m; i++)
            for(int j=0; j<n; j++)
                if(grid[i][j] == 1)
                    return -1;
        
        // otherwise return the required time
        return time;
    }
};