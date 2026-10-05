class Solution {
    public boolean containsNearbyDuplicate(int[] nums, int k) {
        HashMap<Integer, Integer> map = new HashMap<>();

        int i = 0, j = 0;

        while (j < nums.length) {
            while (Math.abs(i - j) > k) {
                map.put(nums[i], map.get(nums[i]) - 1);

                if (map.get(nums[i]) == 0) {
                    map.remove(nums[i]);
                }

                i++;
            }

            if (map.containsKey(nums[j])) {
                return true;
            }

            map.put(nums[j], map.getOrDefault(nums[j], 0) + 1);
            j++;
        }

        return false;
    }
}