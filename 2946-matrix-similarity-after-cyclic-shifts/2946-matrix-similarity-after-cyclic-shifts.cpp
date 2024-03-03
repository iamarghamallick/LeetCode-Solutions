class Solution {
public:
    bool areSimilar(vector<vector<int>>& mat, int k) {
        int n = mat.size();
        int m = mat[0].size();
        
        // Reduce k shifts to (k % n) shifts as after n shifts the matrix will become similar to the initial matrix
        k = k % m;
        
        // i-th index of odd indexed rows should match with ((i + k) % n)-th index
        // i-th index of even indexed rows should match with ((k - i) % n)-th index
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(j % 2 == 1) { // odd indexed row
                    if(mat[i][j] != mat[i][(j + k) % m])
                        return false;
                }
                
                if(j % 2 == 0) { // even indexed row
                    if(mat[i][j] != mat[i][(j + m - k) % m])
                        return false;
                }
            }
        }
        
        return true;
    }
};