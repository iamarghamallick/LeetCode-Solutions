class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& mat) {
        int r = mat.size();
        int c = mat[0].size();
        vector<vector<int>> ans(c, vector<int>(r));
        
        for(int i=0; i<r; i++) {
            for(int j=0; j<c; j++) {
                ans[j][i] = mat[i][j];
            }
        }
        
        return ans;
    }
};