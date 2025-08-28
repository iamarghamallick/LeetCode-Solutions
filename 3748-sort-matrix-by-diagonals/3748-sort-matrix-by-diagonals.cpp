class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int n = grid.size();

        // bottom-left triangle -> decreasing order
        int idx = 0;
        while(idx < n) {
            int i = idx, j = 0;
            priority_queue<int> pq;

            while(i < n && j < n) {
                pq.push(grid[i][j]);
                i++, j++;
            }

            i = idx, j = 0;
            while(i < n && j < n) {
                grid[i][j] = pq.top();
                pq.pop();
                i++, j++;
            }

            idx++;
        }

        // top-right triangle -> increasing order
        idx = 1;
        while(idx < n) {
            int i = 0, j = idx;
            priority_queue<int, vector<int>, greater<int>> pq;

            while(i < n && j < n) {
                pq.push(grid[i][j]);
                i++, j++;
            }

            i = 0, j = idx;
            while(i < n && j < n) {
                grid[i][j] = pq.top();
                pq.pop();
                i++, j++;
            }

            idx++;
        }

        return grid;
    }
};