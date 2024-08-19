class Solution {
public:
    int n;
    vector<vector<int>> dp;
    
    int minSteps(int n) {
        if(n == 1)  return 0;
        this->n = n;
        
        dp = vector<vector<int>>(n + 1, vector<int>(n / 2 + 1, 0));
        
        return 1 + solve(1, 1);
    }
    
    int solve(int currLen, int pasteLen) {
        if(currLen == n)    return 0;
        if(currLen > n) return 1000;
        
        if(dp[currLen][pasteLen])   return dp[currLen][pasteLen];
        
        int opt1 = 1 + solve(currLen + pasteLen, pasteLen);
        int opt2 = 2 + solve(currLen * 2, currLen);
        
        return dp[currLen][pasteLen] = min(opt1, opt2);
    }
};