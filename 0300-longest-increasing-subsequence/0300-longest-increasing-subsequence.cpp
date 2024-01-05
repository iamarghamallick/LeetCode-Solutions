class Solution {
public:
    int f(int idx, int prev_idx, int n, vector<int>& a, vector<vector<int> >& dp) {
        if(idx == n) 
            return 0;
 
        if(dp[idx][prev_idx + 1] != -1)
            return dp[idx][prev_idx + 1];
 
        int notTake = 0 + f(idx + 1, prev_idx, n, a, dp);
        int take = INT_MIN;
        if(prev_idx == -1 || a[idx] > a[prev_idx])
            take = 1 + f(idx + 1, idx, n, a, dp);
 
        return dp[idx][prev_idx + 1] = max(take, notTake);
    }
    
    int lengthOfLIS(vector<int>& a) {
        int n = a.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
        return f(0, -1, n, a, dp);
    }
};