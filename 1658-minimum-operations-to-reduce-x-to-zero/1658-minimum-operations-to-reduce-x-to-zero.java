class Solution {
    public int minOperations(int[] nums, int x) {
        int n = nums.length;
        int sum = 0;

        for (int num : nums) {
            sum += num;
        }

        int k = sum - x;

        if (k < 0) return -1;
        if (k == 0) return n;

        int maxSize = -1;
        int currSum = 0;
        int left = 0, right = 0;

        for (; right < n; right++) {
            currSum += nums[right];
            while (left < n && currSum > k) {
                currSum -= nums[left];
                left++;
            }
            if (currSum == k) {
                maxSize = Math.max(maxSize, right - left + 1);
            }
        }

        return maxSize == -1 ? -1 : n - maxSize;
    }
}