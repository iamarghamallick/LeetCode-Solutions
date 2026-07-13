class Solution {
    public List<Integer> sequentialDigits(int low, int high) {
        List<Integer> ans = new ArrayList<>();

        for(int start = 1; start < 10; start++) {
            int cur = start + 1;
            int val = start;

            if(val >= low && val <= high)
                ans.add(val);

            for(; cur < 10; cur++) {
                val *= 10;
                val += cur;


                if(val >= low && val <= high)
                    ans.add(val);
            }
        }

        Collections.sort(ans);
        return ans;
    }
}