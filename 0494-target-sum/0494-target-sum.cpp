class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int sum = 0;
        for(auto num: nums)
            sum += num;
        
        // initializing dp array
        int dp[n + 1][sum + 1];
        
        for(int j=0; j<=sum; j++)
            dp[0][j] = 0;
        for(int i=0; i<=n; i++)
            dp[i][0] = 1;
        
        // corner cases
        if (sum < abs(target) || (sum + target) & 1)
            return 0;
        
        // subset sum problem with sum = (target + sum) / 2
        sum = (target + sum) / 2;
        
        for(int i=1; i<=n; i++) {
            for(int j=0; j<=sum; j++) {
                if(nums[i-1] <= j) {
                    // we have two choise
                    dp[i][j] = dp[i-1][j - nums[i - 1]] + dp[i-1][j];
                } else {
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        
        return dp[n][sum];
    }
};