class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int n = colors.size();
        vector<vector<int>> dp(n+1, vector<int> (27, 0));
        
        const int inf = 1e9;
        
        for(int i=n-1; i>=0; i--) {
            for(int j=0; j<27; j++) {
                int remove, noRemove;
                
                remove = neededTime[i] + dp[i+1][j];
                noRemove = dp[i+1][colors[i] - 'a' + 1];
                
                if(colors[i] - 'a' + 1 == j)
                    dp[i][j] = remove;
                else
                    dp[i][j] = min(remove, noRemove);
            }
        }
        
        return dp[0][0];
    }
};