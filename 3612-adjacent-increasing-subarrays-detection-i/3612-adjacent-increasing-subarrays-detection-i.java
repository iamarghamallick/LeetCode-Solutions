class Solution {
    public boolean hasIncreasingSubarrays(List<Integer> nums, int k) {
        int n = nums.size();
        int inc = 1, prevInc = 0;
        for (int i = 1; i < n; i++) {
            if (nums.get(i) > nums.get(i - 1))
                inc++;
            else {
                prevInc = inc;
                inc = 1;
            }
            int maxLen = Math.min(prevInc, inc);
            if (maxLen >= k || inc >= 2 * k)
                return true;
        }
        return false;
    }
}