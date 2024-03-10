class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();
        int dp[n + 1][m + 1];
        
        // initialization
        for(int i=0; i<=n; i++)
            dp[i][0] = 0;
        for(int j=0; j<=m; j++)
            dp[0][j] = 0;
        
        // next part
        for(int i=1; i<=n; i++) {
            for(int j=1; j<=m; j++) {
                if(text1[i-1] == text2[j-1])
                    dp[i][j] = 1 + dp[i-1][j-1];
                else
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
        
        // PRINTING LONGEST COMMON SUBSEQUENCE
        string s = "";
        // Starting from dp[n][m] backtrack to dp[0][j] or dp[i][0], conditionally
        int i = n, j = m;
        
        while(i > 0 && j > 0) {
            if(text1[i-1] == text2[j-1]) {
                s = text1[i-1] + s;
                i--; j--;
            }
            
            // else conditionally decrement i or j
            else if(dp[i-1][j] > dp[i][j-1])
                i--;
            else
                j--;
        }
        
        cout << s;

        return dp[n][m];
    }
};