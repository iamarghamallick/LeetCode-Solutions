class Solution {
public:
    vector<vector<int>> modifiedMatrix(vector<vector<int>>& mat) {
        vector<int> a(mat[0].size(), -1);
        
        for(int i=0; i<mat.size(); i++) {
            for(int j=0; j<mat[0].size(); j++) {
                if(mat[i][j] == -1) {
                    // we need to update its value with maxvalue of j-th col
                    if(a[j] == -1) {
                        for(int k=0; k<mat.size(); k++)
                            a[j] = max(a[j], mat[k][j]);
                        mat[i][j] = a[j];
                    } else {
                        mat[i][j] = a[j];
                    }
                }
            }
        }
        
        return mat;
    }
};