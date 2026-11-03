class Solution {
    public int minMoves(int[] nums) {
        int maxVal = nums[0];
        for (int num : nums) {
            maxVal = Math.max(maxVal, num);
        }
        int ans = 0;
        for (int num : nums) {
            ans += maxVal - num;
        }
        return ans;
    }
}