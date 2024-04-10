class Solution {
public:
    int dp[501][501];
    
    int solve(int i, int j, string s1, string s2) {
        // Base Cases
        // 1. Both strings are ended, i.e, matched -> return 0
        // 2. s1 is ended -> only one option : insert all the remaining chars of s2
        // 3. s2 is ended -> only one option : delete all the remaining chars of s2
        if(i < 0 && j < 0)  return 0;
        if(i < 0)   return j+1;
        if(j < 0)   return i+1;
        
        // if we found memoized value
        if(dp[i][j])    return dp[i][j];
        
        // main logic starts here
        // if we see the curr chars of both the strings are same
        // matched is found, no operation needed, go to next char of both
        if(s1[i] == s2[j])
            return dp[i][j] = solve(i-1, j-1, s1, s2);
        
        // otherwise we have 3 choise -> 1. Insert, 2. Delete, 3. Replace
        return dp[i][j] = min(1 + solve(i, j-1, s1, s2), // 1. insert
                          min(1 + solve(i-1, j, s1, s2), // 2. delete
                              1 + solve(i-1, j-1, s1, s2))); // 3. replace
    }
    
    int minDistance(string word1, string word2) {
        int m = word1.size();
        int n = word2.size();
        
        memset(dp, 0, sizeof(dp));
        
        return solve(m-1, n-1, word1, word2);
    }
};