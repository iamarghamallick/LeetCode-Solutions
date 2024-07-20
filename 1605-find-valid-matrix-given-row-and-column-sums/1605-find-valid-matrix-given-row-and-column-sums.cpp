class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rSum, vector<int>& cSum) {
        int n = rSum.size(), m = cSum.size();
        vector<int> currRSum(n, 0), currCSum(m, 0);
        vector<vector<int>> ans(n, vector<int>(m, 0));
        
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                ans[i][j] = min(rSum[i] - currRSum[i], cSum[j] - currCSum[j]);
                currRSum[i] += ans[i][j];
                currCSum[j] += ans[i][j];
            }
        }
        
        return ans;
    }
};