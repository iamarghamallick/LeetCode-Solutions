class Solution {
public:
    int minDistance(string word1, string word2) {
        // DP : Mother problem : Longest common subsequence
        // Answer = (|word1| - |LCS|) + (|word2| - |LCS|)
        
        int m = word1.size();
        int n = word2.size();
        
        int dp[m+1][n+1];
        
        for(int i=0; i<=m; i++) {
            for(int j=0; j<=n; j++) {
                if(i == 0 || j == 0) // initialization
                    dp[i][j] = 0;
                    
                // main logic
                else if(word1[i-1] == word2[j-1])
                    dp[i][j] = 1 + dp[i-1][j-1];
                else 
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
        
        return (m - dp[m][n]) + (n - dp[m][n]);
    }
};