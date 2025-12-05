class Solution {
    public int countPartitions(int[] nums) {
        int tot = 0;
        for(int num: nums) tot += num;
        int res = 0;
        int part1 = 0;
        for(int i=0; i<nums.length-1; i++) {
            part1 += nums[i];
            int part2 = tot - part1;
            if((part1 - part2) % 2 == 0)
                res++;
        }
        return res;
    }
}