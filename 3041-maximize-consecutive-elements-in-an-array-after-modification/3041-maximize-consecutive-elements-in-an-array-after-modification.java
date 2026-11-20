class Solution {
    public int maxSelectedElements(int[] nums) {
        Arrays.sort(nums);
        int maxVal = nums[nums.length - 1];
        int[] dp = new int[maxVal + 2];
        int maxLen = 1;
        for (int val : nums) {
            dp[val + 1] = dp[val] + 1;
            dp[val] = dp[val - 1] + 1;
            maxLen = Math.max(maxLen, Math.max(dp[val], dp[val + 1]));
        }
        return maxLen;
    }
}