class Solution {
    public int[] countServers(int n, int[][] logs, int x, int[] queries) {
        Arrays.sort(logs,
                (a, b) -> Integer.compare(a[1], b[1]));

        int m = queries.length;
        Integer[] ids = new Integer[m];

        for (int i = 0; i < m; i++) {
            ids[i] = i;
        }

        Arrays.sort(ids,
                (a, b) -> Integer.compare(queries[a], queries[b]));

        int[] ans = new int[m];
        int[] count = new int[n + 1];
        int left = 0, right = 0, active = 0;

        for (Integer i : ids) {
            int q = queries[i];

            while (right < logs.length && logs[right][1] <= q) {
                int id = logs[right][0];
                count[id]++;
                if (count[id] == 1) {
                    active++;
                }
                right++;
            }

            while (left < logs.length && logs[left][1] < q - x) {
                int id = logs[left][0];
                count[id]--;
                if (count[id] == 0) {
                    active--;
                }
                left++;
            }

            ans[i] = n - active;
        }

        return ans;
    }
}