class Solution {
    public int[] searchRange(int[] nums, int target) {
        int leftMostIdx = search(nums, target, "left");
        int rightMostIdx = search(nums, target, "right");

        return new int[] { leftMostIdx, rightMostIdx };
    }

    public int search(int[] nums, int target, String dir) {
        int ans = -1;

        int left = 0;
        int right = nums.length - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (target == nums[mid]) {
                ans = mid;

                if (dir == "left") {
                    right = mid - 1;
                } else if (dir == "right") {
                    left = mid + 1;
                }
            } else if (target < nums[mid]) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        return ans;
    }
}