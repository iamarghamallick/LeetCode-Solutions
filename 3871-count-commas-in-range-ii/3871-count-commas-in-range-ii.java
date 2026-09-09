class Solution {
    public long countCommas(long n) {
        // 1 <= n <= 10^15
        // 1-3 digits => 0 comma
        // 4-6 digits => 1 comma
        // 7-9 digits => 2 comma
        // 10-12 digits => 3 comma
        // 13-15 digits => 4 comma
        // 16 digits => 5 comma

        long ans = 0;

        ans += n - 999999999999999L > 0 ? n - 999999999999999L : 0;
        ans += n - 999999999999L > 0 ? n - 999999999999L : 0;
        ans += n - 999999999 > 0 ? n - 999999999 : 0;
        ans += n - 999999 > 0 ? n - 999999 : 0;
        ans += n - 999 > 0 ? n - 999 : 0;

        return ans;
    }
}