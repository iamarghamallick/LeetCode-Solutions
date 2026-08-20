class Solution {
    public int[] resultArray(int[] nums) {
        ArrayList<Integer> left = new ArrayList<>();
        ArrayList<Integer> right = new ArrayList<>();

        for(int i=0; i<nums.length; i++) {
            if(i == 0) left.add(nums[i]);
            else if(i == 1) right.add(nums[i]);
            else if(left.get(left.size()-1) > right.get(right.size()-1)) {
                left.add(nums[i]);
            } else {
                right.add(nums[i]);
            }
        }

        int idx = 0;
        for(int i=0; i<left.size(); i++) {
            nums[idx++] = left.get(i);
        }
        for(int i=0; i<right.size(); i++) {
            nums[idx++] = right.get(i);
        }

        return nums;
    }
}