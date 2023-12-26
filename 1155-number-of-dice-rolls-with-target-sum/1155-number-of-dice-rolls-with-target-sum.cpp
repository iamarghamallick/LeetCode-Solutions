class Solution {
public:
    int numRollsToTarget(int n, int k, int target) {
        vector<vector<int>> dp(n+1, vector<int>(k * n+1, 0));
        
        if(target > k*n)
            return 0;
    
        dp[n][target] = 1;
        
        const int mod = 1e9+7;
        
        for(int i=n-1; i>=0; i--) {
            for(int j=0; j<=k*i; j++) {
                for(int z=1; z<=k; z++) 
                    dp[i][j] = (dp[i][j] + dp[i+1][j+z]) % mod;
            }
        }
        
        return dp[0][0];
    }
};