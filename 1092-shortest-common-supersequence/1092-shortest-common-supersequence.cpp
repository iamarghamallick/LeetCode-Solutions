class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        // DP : Mother Problem - Printing the Longest Common Subsequence
        // First we find the length of the LCS(str1, str2),
        // filling up the dp[][] array
        // Then we have to back-track through the dp[][] array
        // till we reach dp[0][j] or dp[i][0] to find SCS
        
        int m = str1.size();
        int n = str2.size();
        
        int dp[m+1][n+1];
        
        for(int i=0; i<=m; i++) {
            for(int j=0; j<=n; j++) {
                // Initialization
                if(i == 0 || j == 0)
                    dp[i][j] = 0;
                
                // next logic
                else if(str1[i-1] == str2[j-1])
                    dp[i][j] = 1 + dp[i-1][j-1];
                else 
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
        
        // PRINTING SCS
        string s = "";
        int i = m, j = n;
        
        while(i > 0 && j > 0) {
            if(str1[i-1] == str2[j-1]) {
                s += str1[i-1];
                i--; j--;
            }
            
            // Notice the code variation here
            else if(dp[i][j-1] > dp[i-1][j]) {
                s += str2[j-1];
                j--;
            } else {
                s += str1[i-1];
                i--;
            }
        }
        
        // include the remaining chars of str1 or str2 (if any)
        while(i > 0) {
            s += str1[i-1];
            i--;
        }
        while(j > 0) {
            s += str2[j-1];
            j--;
        }
        
        // finally reverse the string s to find required SCS
        reverse(s.begin(), s.end());
        
        return s;
    }
};