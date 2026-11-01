class Solution {
    public int minMoves(int[] nums) {
        int mini = nums[0];
        
        for (int num : nums) {
            mini = Math.min(mini, num);
        }

        int ans = 0;

        for (int num : nums) {
            ans += num - mini;
        }

        return ans;
    }
}