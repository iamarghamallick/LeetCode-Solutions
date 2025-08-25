class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        vector<int> ans;
        bool dir = true;
        int i = 0, j = 0;

        while(i<n && j<m) {
            ans.push_back(mat[i][j]);
            
            int nI = i + (dir ? -1 : 1);
            int nJ = j + (dir ? 1 : -1);

            if(nI<0 || nI==n || nJ<0 || nJ==m) {
                if(dir) {
                    // up-right
                    if(j == m-1) i++;        // last column → move down
                    else j++;                // otherwise → move right
                } else {
                    // down-left
                    if(i == n-1) j++;        // last row → move right
                    else i++;                // otherwise → move down
                }
                dir = !dir;
            } else {
                i = nI;
                j = nJ;
            }
        }

        return ans;
    }
};