class Solution {
    public long getDescentPeriods(int[] prices) {
        int n = prices.length;
        long ans = 0;
        int start = 0;
        for(int end=1; end<n; end++) {
            if(prices[end-1] - prices[end] != 1) {
                int len = end - start;
                ans += ((long)len * (len + 1)) / 2;
                start = end;
            }
        }
        int len = n - start;
        ans += ((long)len * (len + 1)) / 2;
        return ans;
    }
}