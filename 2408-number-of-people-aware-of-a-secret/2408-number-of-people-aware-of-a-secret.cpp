class Solution {
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        int MOD = 1e9 + 7;
        vector<long long> dp(n + 1, 0);
        dp[1] = 1;

        for (int day = 1; day <= n; day++) {
            int sharers = dp[day];
            if (sharers == 0)
                continue;

            for (int j = day + delay; j < day + forget && j <= n; j++) {
                dp[j] = (dp[j] + sharers) % MOD;
            }
        }

        long long ans = 0;
        for (int day = n - forget + 1; day <= n; day++) {
            ans = (ans + dp[day]) % MOD;
        }

        return (int)ans;
    }
};