class Solution {
    public int[] assignTasks(int[] servers, int[] tasks) {
        int n = servers.length;
        int m = tasks.length;
        int[] ans = new int[m];

        PriorityQueue<int[]> available = new PriorityQueue<>((a, b) -> {
            if (a[1] != b[1]) {
                return Integer.compare(a[1], b[1]);
            }
            return Integer.compare(a[0], b[0]);
        }); // {index, value}

        PriorityQueue<int[]> unavailable = new PriorityQueue<>((a, b) -> {
            if (a[1] != b[1]) {
                return Integer.compare(a[1], b[1]);
            }
            return Integer.compare(a[0], b[0]);
        }); // {index, time}

        for (int i = 0; i < n; i++) {
            available.offer(new int[] { i, servers[i] });
        }

        int t = 0;

        for (int j = 0; j < m; j++) {
            t = Math.max(t, j);
            release(available, unavailable, servers, t);
            if (available.isEmpty()) {
                t = unavailable.peek()[1];
                release(available, unavailable, servers, t);
            }

            int[] server = available.poll();
            int index = server[0];
            ans[j] = index;
            unavailable.offer(new int[] { index, t + tasks[j] });
        }

        return ans;
    }

    private void release(PriorityQueue<int[]> available, PriorityQueue<int[]> unavailable, int[] servers, int t) {
        while (!unavailable.isEmpty() && unavailable.peek()[1] <= t) {
            int[] server = unavailable.poll();
            int index = server[0];
            available.offer(new int[] { index, servers[index] });
        }
    }
}