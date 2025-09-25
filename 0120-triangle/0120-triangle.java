class Solution {
    public int minimumTotal(List<List<Integer>> triangle) {
        int n = triangle.size();

        for (int i = 1; i < n; i++) {
            int m = triangle.get(i).size();
            for (int j = 0; j < m; j++) {
                int val = triangle.get(i).get(j);

                if (j == 0) {
                    // First element in row, can only come from directly above
                    val += triangle.get(i - 1).get(j);
                } else if (j == m - 1) {
                    // Last element in row, can only come from above-left
                    val += triangle.get(i - 1).get(j - 1);
                } else {
                    // Middle element, choose min of above and above-left
                    val += Math.min(triangle.get(i - 1).get(j - 1),
                                    triangle.get(i - 1).get(j));
                }

                triangle.get(i).set(j, val);
            }
        }

        int ans = Integer.MAX_VALUE;
        for (int num : triangle.get(n - 1)) {
            ans = Math.min(ans, num);
        }

        return ans;
    }
}
