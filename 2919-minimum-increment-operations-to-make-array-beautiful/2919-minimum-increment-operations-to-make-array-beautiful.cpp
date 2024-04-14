class Solution {
public:
    long long dp[100001];
    
    long long minIncrementOperations(vector<int>& nums, int k) {
        long long n = nums.size();
        
        dp[0] = max(0, k - nums[0]);
        dp[1] = max(0, k - nums[1]);
        dp[2] = max(0, k - nums[2]);
        
        for(long long i=3; i<n; i++)
            dp[i] = max(0, k - nums[i]) + min(dp[i-1], min(dp[i-2], dp[i-3]));
        
        return min(dp[n-1], min(dp[n-2], dp[n-3]));
    }
};