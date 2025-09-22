class Solution {
    public int maxFrequencyElements(int[] nums) {
        int maxFreq = 0;
        int count = 0;
        HashMap<Integer, Integer> map = new HashMap<>();

        for(int i=0; i<nums.length; i++) {
            map.put(nums[i], map.getOrDefault(nums[i], 0) + 1);
            maxFreq = Math.max(maxFreq, map.get(nums[i]));
        }
        
        for(int i=0; i<nums.length; i++) {
            if(map.get(nums[i]) == maxFreq)
                count++;
        }

        return count;
    }
}