class Solution {
    public int maximumSaleItems(int[][] items, int budget) {
        int n = items.length;
        int[] freeCopies = new int[n];
        int minPrice = Integer.MAX_VALUE;

        for (int i = 0; i < n; i++) {
            minPrice = Math.min(minPrice, items[i][1]);

            for (int j = 0; j < n; j++) {
                if (i != j &&
                        items[i][0] != 0 &&
                        items[j][0] % items[i][0] == 0) {
                    freeCopies[i]++;
                }
            }
        }

        int[] dp = new int[budget + 1];

        Arrays.fill(dp, -1);
        dp[0] = 0;

        for (int i = 0; i < n; i++) {
            int price = items[i][1];
            int gain = 1 + freeCopies[i];

            for (int j = budget; j >= price; j--) {
                if (dp[j - price] != -1) {
                    dp[j] = Math.max(
                            dp[j],
                            dp[j - price] + gain);
                }
            }
        }

        int ans = 0;

        for (int cost = 0; cost <= budget; cost++) {
            if (dp[cost] == -1) {
                continue;
            }

            int remainingBudget = budget - cost;
            int extraCopies = remainingBudget / minPrice;

            ans = Math.max(ans, dp[cost] + extraCopies);
        }

        return ans;
    }
}