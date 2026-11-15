class Solution {

    private final int MOD = 1000000007;

    public int numOfSubarrays(int[] arr) {
        int n = arr.length;
        int ans = 0;

        int[][] dp = new int[2][2];

        for (int i = 0; i < n; i++) {
            int idx = i & 1;
            int parity = arr[i] & 1;

            dp[parity][idx] = (1 + dp[0][1 - idx]) % MOD;
            dp[1 - parity][idx] = dp[1][1 - idx] % MOD;

            ans = (ans + dp[1][idx]) % MOD;
        }

        // for (int i = 0; i < n; i++) {
        //     int sum = 0;
        //     for (int j = i; j < n; j++) {
        //         sum += arr[j];
        //         if (sum % 2 == 1) {
        //             ans++;
        //         }
        //     }
        // }

        return ans;
    }
}