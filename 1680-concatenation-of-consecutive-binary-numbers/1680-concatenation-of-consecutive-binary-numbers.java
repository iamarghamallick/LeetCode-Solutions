class Solution {
    public int concatenatedBinary(int n) {
        long result = 0;
        int mod = 1000000007;

        for (int num = 1; num <= n; num++) {
            int digits = 32 - Integer.numberOfLeadingZeros(num);
            result = ((result << digits) + num) % mod;
        }

        return (int) result;
    }
}