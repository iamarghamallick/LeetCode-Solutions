class Solution {
    public long maxAlternatingSum(int[] nums) {
        int n = nums.length;

        for (int i = 0; i < n; i++) {
            nums[i] *= nums[i];
        }

        Arrays.sort(nums);
        long ans = 0;
        int k = (n % 2 == 0) ? (n / 2) : (n + 1) / 2;

        for (int i = 0; i < k; i++) {
            ans += nums[n - i - 1];
        }

        for (int i = k; i < n; i++) {
            ans -= nums[n - i - 1];
        }

        return ans;
    }
}