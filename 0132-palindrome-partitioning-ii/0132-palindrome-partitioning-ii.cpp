class Solution {    
public:
    bool isPalindrom(string &str, int i, int j) {
        while(i < j) {
            if(str[i] != str[j]) 
                return false;
            i++, j--;
        }
        
        return true;
    }
    
    // Approch 2: Memoized Recursion
    vector<vector<int>> dp;
    
    int solve(string& str, int i, int j) {
        // base condition
        // or if the string is already a palindrom, no partitioning needed
        if(i >= j || isPalindrom(str, i, j))  return 0;
        
        // if the current sub-problem is already solved
        if(dp[i][j] != -1)  return dp[i][j];
        
        // next logic
        int ans = INT_MAX;
        for(int k=i; k<j; k++) {
            if(isPalindrom(str, i, k)) {
                int tempAns = solve(str, i, k) + solve(str, k+1, j) + 1;
                ans = min(ans, tempAns);
            }
        }
        
        // store the result, then return 
        return dp[i][j] = ans;
    }
    
    int minCut(string str) {     
        // initializing dp array
        dp.resize(str.length(), vector<int>(str.length(), -1));
        
        // function call
        return solve(str, 0, str.length()-1);
    }
};