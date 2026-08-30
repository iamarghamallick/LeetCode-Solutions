class Solution {
    public int minimumDeletions(int[] nums) {
        int min = 0;
        int max = 0;
        for (int i = 0; i < nums.length; i++) {
            if (nums[i] <= nums[min]) {
                min = i;
            }

            if (nums[i] >= nums[max]) {
                max = i;
            }
        }

        // Scenario 1: Both elements are removed by only deleting from the front
        int s1 = Math.max(min, max) + 1;

        // Scenario 2: Both elements are removed by only deleting from the back
        int s2 = nums.length - Math.min(min, max);

        // Scenario 3: Delete from the front to remove one of the elements, and delete from the back to remove the other element
        int s3 = (Math.min(min, max) + 1) + (nums.length - Math.max(min, max));

        return Math.min(s1, Math.min(s2, s3));
    }
}