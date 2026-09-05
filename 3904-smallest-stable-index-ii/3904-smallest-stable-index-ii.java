class Solution {
    public int firstStableIndex(int[] nums, int k) {
        int n = nums.length;
        int[] maxi = new int[n];
        int[] mini = new int[n];

        for (int i = 0; i < n; i++) {
            maxi[i] = i == 0 ? nums[i] : Math.max(maxi[i - 1], nums[i]);
        }

        for (int i = n - 1; i >= 0; i--) {
            mini[i] = i == n - 1 ? nums[i] : Math.min(mini[i + 1], nums[i]);
        }

        for (int i = 0; i < n; i++) {
            if (maxi[i] - mini[i] <= k) {
                return i;
            }
        }

        return -1;
    }
}