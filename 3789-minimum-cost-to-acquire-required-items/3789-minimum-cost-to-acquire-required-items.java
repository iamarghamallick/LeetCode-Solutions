class Solution {
    public long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        long ans = 0;

        int minNeed = Math.min(need1, need2);
        int maxNeed = Math.max(need1, need2);

        ans += 1L * minNeed * Math.min(costBoth, cost1 + cost2);

        long remaining = maxNeed - minNeed;

        ans += 1L * remaining * Math.min(costBoth, need1 > need2 ? cost1 : cost2);

        return ans;
    }
}