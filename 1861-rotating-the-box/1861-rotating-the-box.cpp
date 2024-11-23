class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        int n = box.size();
        int m = box[0].size();
        
        for(int i=0; i<n; i++) {
            int k = m-1;
            for(int j=m-1; j>=0; j--) {
                if(box[i][j] == '.')
                    continue;
                else if(box[i][j] == '*')
                    k = j-1;
                else {
                    box[i][j] = '.';
                    box[i][k] = '#';
                    k--;
                }
            }
        }
        
        vector<vector<char>> res(m, vector<char>(n));
        for(int i=0; i<n; i++)
            for(int j=0; j<m; j++)
                res[j][i] = box[i][j];
        
        for(int i=0; i<m; i++)
            reverse(res[i].begin(), res[i].end());
        
        return res;
    }
};