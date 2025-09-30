class Solution {
    public int triangularSum(int[] nums) {
        int n = nums.length;
        if(n == 1) return nums[0];
        int[] temp = new int[n-1];
        for(int i=1; i<n; i++)
            temp[i-1] = (nums[i-1] + nums[i]) % 10;
        return triangularSum(temp);
    }
}