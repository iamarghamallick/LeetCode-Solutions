class Solution {
public:
    vector<vector<int>> directions {{0, 1}, {0, -1}, {1, 0}, {-1, 0}}; // allowed moves are [[right], [left], [down], [up]]
    
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int r = maze.size();
        int c = maze[0].size();
        
        queue<pair<int, int>> q; // queue of (i, j)
        q.push({ entrance[0], entrance[1] }); // starting from the entrance
        maze[entrance[0]][entrance[1]] = '+'; // mark visited with '+'
        
        int step = 0;
        
        while(!q.empty()) {
            int n = q.size();
            
            while(n--) {
                pair<int, int> temp = q.front(); q.pop();
                
                // check if it is the boundary
                // and not entrance (since you are not allowed to exit from entrance itself)
                // return step, no more travarsal required
                int i = temp.first;
                int j = temp.second;
                
                if(temp != make_pair(entrance[0], entrance[1]) && (i == 0 || i == r - 1 || j == 0 || j == c - 1))
                    return step;
                
                // explore the neighbours
                for(auto& dir : directions) {
                    int new_i = i + dir[0];
                    int new_j = j + dir[1];
                    
                    // check if moving in this direction(dir) is possible
                    // if it is inside the boundary and it has no wall
                    if((new_i >= 0 && new_i < r && new_j >= 0 && new_j < c) && maze[new_i][new_j] != '+') {
                        // add into the queue
                        // mark as visited with '+' in the maze array
                        q.push({ new_i, new_j });
                        maze[new_i][new_j] = '+';
                    }
                }
            }
            
            step++;
        }
        
        return -1;
    }
};