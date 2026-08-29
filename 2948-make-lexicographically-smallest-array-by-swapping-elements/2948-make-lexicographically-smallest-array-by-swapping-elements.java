class Solution {
    public int[] lexicographicallySmallestArray(int[] nums, int limit) {
        int n = nums.length;
        int[] sorted = nums.clone();
        Arrays.sort(sorted);

        int groups = 0;
        HashMap<Integer, Integer> mapToGroup = new HashMap<>();
        mapToGroup.put(sorted[0], groups);
        for(int i=1; i<n; i++) {
            if(sorted[i] - sorted[i-1] <= limit) {
                mapToGroup.put(sorted[i], groups);
            } else {
                groups++;
                mapToGroup.put(sorted[i], groups);
            }
        }

        HashMap<Integer, ArrayList<Integer>> mapToList = new HashMap<>();
        for(int group=0; group<=groups; group++) {
            mapToList.put(group, new ArrayList<>());
        }

        for(int i=0; i<n; i++) {
            int group = mapToGroup.get(sorted[i]);
            ArrayList<Integer> list = mapToList.get(group);
            list.add(sorted[i]);
            mapToList.put(group, list);
        }

        for(int i=0; i<n; i++) {
            int group = mapToGroup.get(nums[i]);
            ArrayList<Integer> list = mapToList.get(group);
            nums[i] = list.get(0);
            list.remove(0);
            mapToList.put(group, list);
        }

        return nums;
    }
}