class Solution {
    public int search(int[] nums, int target) {
        int index = Collections.binarySearch(
            Arrays.stream(nums).boxed().toList(),
        target);

        return index >= 0 ? index : -1;
    }
}