class Solution {
    public int triangleNumber(int[] nums) {
        int n = nums.length;
        Arrays.sort(nums);
        int count = 0;

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int key = nums[i] + nums[j];
                int k = getLastSmaller(nums, key);
                if (k > j) {
                    count += (k - j);
                }
            }
        }

        return count;
    }

    private int getLastSmaller(int[] nums, int key) {
        int low = 0, high = nums.length - 1, ans = -1;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (nums[mid] < key) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return ans;
    }
}
