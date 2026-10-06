class Solution {
    public List<String> summaryRanges(int[] nums) {
        int n = nums.length;

        if (n == 0) {
            return new ArrayList<>();
        }

        if (n == 1) {
            return List.of(Integer.toString(nums[0]));
        }

        List<String> ans = new ArrayList<>();

        int i = 0;
        while (i < n) {
            int start = nums[i];
            int prev = start;
            i++;

            while (i < n && nums[i] == prev + 1) {
                prev = nums[i];
                i++;
            }

            if(start == prev) {
                ans.add(Integer.toString(start));
            } else {
                ans.add(Integer.toString(start) + 
                        "->" +
                        Integer.toString(prev));
            }
        }

        return ans;
    }
}