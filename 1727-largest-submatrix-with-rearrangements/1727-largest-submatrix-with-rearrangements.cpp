class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        int ans = 0;
        
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(mat[i][j] != 0 && i>0)
                    mat[i][j] += mat[i-1][j];
            }
            
            vector<int> currRow = mat[i];
            sort(currRow.begin(), currRow.end(), greater());
            for(int k=0; k<n; k++) {
                ans = max(ans, currRow[k]*(k+1));
            }
        }
        
        return ans;
    }
};