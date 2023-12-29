class Solution {
public:
    int minDifficulty(vector<int>& arr, int d) {
        int n = arr.size();
        
        const int inf = 1e5;
        
        vector<vector<int>> dp(n+1, vector<int>(d+1, inf));
        dp[n][d] = 0;
        
        for(int i=n-1; i>=0; i--) {
            for(int j=d-1; j>=0; j--) {
                int MAX = 0;
                for(int k=i; k<n; k++) {
                    MAX = max(MAX, arr[k]);
                    dp[i][j] = min(dp[i][j], MAX + dp[k+1][j+1]);
                }
            }
        }
        
        return dp[0][0] >= inf ? -1 : dp[0][0];
    }
};