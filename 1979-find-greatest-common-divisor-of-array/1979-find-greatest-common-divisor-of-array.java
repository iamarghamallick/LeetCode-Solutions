class Solution {
    public int findGCD(int[] nums) {
        int mn = nums[0];
        int mx = nums[0];
        for(int num: nums) {
            mn = Math.min(mn, num);
            mx = Math.max(mx, num);
        }
        return gcd(mn, mx);
    }

    private int gcd(int a, int b) {
        if(b == 0) {
            return a;
        }
        return gcd(b, a % b);
    }
}