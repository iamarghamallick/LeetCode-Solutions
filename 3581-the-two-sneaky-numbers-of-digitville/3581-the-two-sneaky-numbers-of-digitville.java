class Solution {
    public int[] getSneakyNumbers(int[] nums) {
        Arrays.sort(nums);
        List<Integer> ans = new ArrayList<>();
        int index = 0;
        for(int i=0; i<nums.length; i++) {
            if(index != nums[i]) {
                ans.add(nums[i]);
            } else {
                index++;
            }
        }
        return new int[] {ans.get(0), ans.get(1)};
    }
}