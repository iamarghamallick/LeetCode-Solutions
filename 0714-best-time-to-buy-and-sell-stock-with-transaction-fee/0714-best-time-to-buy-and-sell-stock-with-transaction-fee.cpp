class Solution {
public:
    int dp[50001][2];
    
    int solve(int i, bool buy, vector<int>& prices, int fee) {
        int n = prices.size();
        
        // Base Case
        if(i == n)  return 0;
        
        // If the current sub-problem is already solved
        if(dp[i][buy])  return dp[i][buy];
        
        // Otherwise, main logic
        // There are two cases
        // 1. Allowed to buy the current stock
        //    Two options are there ->
        //      i.  Buy (add the price and don't allow to buy again)
        //      ii. Do not buy, go to the next one
        if(buy)
            return dp[i][buy] = max(prices[i] + solve(i+1, 0, prices, fee),
                                                solve(i+1, 1, prices, fee));
        
        // 2. Allowed to sell the current stock
        //    Two options are there ->
        //      i.  Sell (deduct the price + transaction fees and allow to buy)
        //      ii. Do not sell, go to the next one
        return dp[i][buy] = max(- fee - prices[i] + solve(i+1, 1, prices, fee),
                                                    solve(i+1, 0, prices, fee));

    }
    
    int maxProfit(vector<int>& prices, int fee) {
        memset(dp, 0, sizeof(dp));
        
        return solve(0, 0, prices, fee);
    }
};