class Solution {
    public int shortestPath(int n, int[][] edges, String labels, int k) {
        ArrayList<int[]>[] adjList = new ArrayList[n];

        Arrays.setAll(adjList, i -> new ArrayList<>());

        for (int[] edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];

            adjList[u].add(new int[] { v, w });
        }

        int[][] result = new int[n][k + 1];

        for (int[] row : result) {
            Arrays.fill(row, Integer.MAX_VALUE);
        }

        PriorityQueue<int[]> pq = new PriorityQueue<>(
                (a, b) -> Integer.compare(a[1], b[1])); // int[] -> [node, dist, count]

        pq.offer(new int[] { 0, 0, 1 });
        result[0][1] = 0;

        while (!pq.isEmpty()) {
            int top[] = pq.poll();

            int node = top[0];
            int dist = top[1];
            int count = top[2];

            if (result[node][count] < dist) {
                continue;
            }

            if (node == n - 1) {
                return dist;
            }

            for (int[] edge : adjList[node]) {
                int nextNode = edge[0];
                int nextWeight = edge[1];

                int newCount = labels.charAt(node) == labels.charAt(nextNode) ? count + 1 : 1;

                if (newCount > k) {
                    continue;
                }

                int newDist = dist + nextWeight;

                if (newDist < result[nextNode][newCount]) {
                    pq.offer(new int[] { nextNode, newDist, newCount });
                    result[nextNode][newCount] = newDist;
                }
            }
        }

        return -1;
    }
}