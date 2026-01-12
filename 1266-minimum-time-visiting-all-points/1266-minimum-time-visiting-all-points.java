class Solution {
    public int minTimeToVisitAllPoints(int[][] points) {
        int time = 0;

        for(int i=1; i<points.length; i++) {
            int x1 = points[i-1][0];
            int y1 = points[i-1][1];

            int x2 = points[i][0];
            int y2 = points[i][1];

            // Advance in diagonal as possible
            int dia = Math.min(Math.abs(x1 - x2), Math.abs(y1 - y2));
            time += dia;

            // Go in straight line
            int str = Math.abs(x1 - x2) - dia;
            int stc = Math.abs(y1 - y2) - dia;
            time += str + stc;
        }

        return time;
    }
}