class Solution {
    public int smallestNumber(int n) {
        int[] nums = {1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024};
        for(int i=0; i<nums.length; i++)
            if(nums[i] - 1 >= n) 
                return nums[i] - 1;
        return 0;
    }
}