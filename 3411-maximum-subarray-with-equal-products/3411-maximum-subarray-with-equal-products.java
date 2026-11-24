class Solution {
    public int maxLength(int[] nums) {
        int n = nums.length;
        int ans = 0;

        for (int i = 0; i < n; i++) {
            long prod = nums[i];
            long gcd = nums[i];
            long lcm = nums[i];

            for (int j = i + 1; j < n; j++) {
                prod *= nums[j];
                gcd = findGCD(gcd, nums[j]);
                lcm = findLCM(lcm, nums[j]);

                if (prod == gcd * lcm) {
                    ans = Math.max(ans, j - i + 1);
                }
            }
        }

        return ans;
    }

    private long findGCD(long a, long b) {
        while (b != 0) {
            long temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }

    private long findLCM(long a, long b) {
        if (a == 0 || b == 0) {
            return 0;
        }

        return Math.abs(a / findGCD(a, b) * b);
    }
}