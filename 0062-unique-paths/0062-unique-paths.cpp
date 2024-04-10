class Solution {
public:
    int dp[101][101];
    
    int solve(int i, int j) {
        if(i == 0 && j == 0)
            return 1;
        if(i < 0 || j < 0)
            return 0;
        
        if(dp[i][j])
            return dp[i][j];
        
        return dp[i][j] = solve(i-1, j) + solve(i, j-1);
    }
    
    int uniquePaths(int m, int n) {
        memset(dp, 0, sizeof(dp));
        return solve(m-1, n-1);
    }
};