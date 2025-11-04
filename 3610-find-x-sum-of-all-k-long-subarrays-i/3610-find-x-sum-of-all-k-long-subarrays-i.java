class Solution {
    public int[] findXSum(int[] nums, int k, int x) {
        int n = nums.length;
        HashMap<Integer, Integer> map = new HashMap<>();
        int[] ans = new int[n - k + 1];

        for (int i = 0; i < k; i++)
            map.put(nums[i], map.getOrDefault(nums[i], 0) + 1);

        ans[0] = getXSum(map, x);

        for (int i = k; i < n; i++) {
            // Remove element going out of window
            int out = nums[i - k];
            map.put(out, map.get(out) - 1);
            if (map.get(out) == 0) map.remove(out);

            // Add new element
            int in = nums[i];
            map.put(in, map.getOrDefault(in, 0) + 1);

            // Compute new x-sum
            ans[i - k + 1] = getXSum(map, x);
        }

        return ans;
    }

    private int getXSum(HashMap<Integer, Integer> map, int x) {
        List<int[]> list = new ArrayList<>();
        for (Map.Entry<Integer, Integer> e : map.entrySet())
            list.add(new int[]{e.getKey(), e.getValue()});

        list.sort((a, b) -> {
            if (a[1] == b[1]) return b[0] - a[0];
            return b[1] - a[1];
        });

        int sum = 0;
        for (int i = 0; i < Math.min(x, list.size()); i++)
            sum += list.get(i)[0] * list.get(i)[1];

        return sum;
    }
}
