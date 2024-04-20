class Solution {
public:
    void dfs(int i, int j, vector<vector<int>>& land, vector<vector<bool>>& visited, vector<int>& res) {
        // checking boundary
        if(i < 0 || i >= land.size() || j < 0 || j >= land[0].size())
            return;
        // if the current location is already visited or contains water
        if(land[i][j] == 0 || visited[i][j])
            return;
        
        // update the res array as follows
        res[0] = min(res[0], i);
        res[1] = min(res[1], j);
        res[2] = max(res[2], i);
        res[3] = max(res[3], j);
        
        // mark the current as visited
        visited[i][j] = true;
        
        // do the dfs calls for all four directions
        dfs(i+1, j, land, visited, res); // down
        dfs(i-1, j, land, visited, res); // up
        dfs(i, j+1, land, visited, res); // right
        dfs(i, j-1, land, visited, res); // left
    }
    
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        int row = land.size();
        int col = land[0].size();
        int count = 0;
        
        vector<vector<bool>> visited(row, vector<bool>(col, false));
        vector<vector<int>> ans;
        
        for(int i=0; i<row; i++) {
            for(int j=0; j<col; j++) {
                if(land[i][j] == 1 && !visited[i][j]) {
                    vector<int> res { INT_MAX, INT_MAX, INT_MIN, INT_MIN };
                    dfs(i, j, land, visited, res);
                    ans.push_back(res);
                }
            }
        }
        
        return ans;
    }
};