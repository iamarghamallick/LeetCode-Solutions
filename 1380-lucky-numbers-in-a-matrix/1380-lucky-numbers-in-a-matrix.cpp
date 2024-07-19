class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        vector<int> minRow, maxCol, ans;
        
        for(int i=0; i<n; i++) {
            int minVal = INT_MAX;
            
            for(int j=0; j<m; j++)
                minVal = min(minVal, mat[i][j]);
            
            minRow.push_back(minVal);
        }
        
        for(int i=0; i<m; i++) {
            int maxVal = INT_MIN;
            
            for(int j=0; j<n; j++)
                maxVal = max(maxVal, mat[j][i]);
            
            maxCol.push_back(maxVal);
        }
        
        for(int i=0; i<n; i++)
            for(int j=0; j<m; j++)
                if(mat[i][j] == minRow[i] && mat[i][j] == maxCol[j])
                    ans.push_back(mat[i][j]);
        
        return ans;
    }
};