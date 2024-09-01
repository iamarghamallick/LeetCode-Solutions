class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& arr, int m, int n) {
        if(arr.size() != m * n)
            return {};
        
        vector<vector<int>> ans(m, vector<int>(n));
        int row = 0, col = 0;
        
        for(int i=0; i<arr.size(); i++) {
            ans[row][col++] = arr[i];
            
            if(col == n) {
                col = 0;
                row++;
            }
        }
        
        return ans;
    }
};