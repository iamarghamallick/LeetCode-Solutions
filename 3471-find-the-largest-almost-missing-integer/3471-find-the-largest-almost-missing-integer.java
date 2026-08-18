class Solution {
    public int largestInteger(int[] nums, int k) {
        int n = nums.length;
        HashMap<Integer, Integer> map = new HashMap<>();
        for(int num: nums) {
            map.put(num, map.getOrDefault(num, 0) + 1);
        }

        if(k == 1) {
            // return the largest num that occurs exactly once
            int largest = -1;
            for(Map.Entry<Integer, Integer> entry: map.entrySet()) {
                if(entry.getValue() == 1) {
                    largest = Math.max(largest, entry.getKey());
                }
            }
            return largest;
        }

        if(k == n) {
            // return the largest num in nums
            int largest = -1;
            for(int num: nums) {
                largest = Math.max(largest, num);
            }
            return largest;
        }

        // return largest of nums[0] and nums[n - 1]
        // if they both occur exactly once in the array
        // if one of them occurs more than once, return the other
        int ans = -1;
        if(map.get(nums[0]) == 1) {
            ans = Math.max(ans, nums[0]);
        } 
        if(map.get(nums[n-1]) == 1) {
            ans = Math.max(ans, nums[n-1]);
        } 
        return ans;
    }
}