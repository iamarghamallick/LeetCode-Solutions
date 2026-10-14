class Solution {
    public String maxSumOfSquares(int num, int sum) {
        StringBuilder n = new StringBuilder();

        for (int i = 0; i < num; i++) {
            int d = Math.min(9, sum);
            n.append(Integer.toString(d));
            sum -= d;
        }

        if (sum > 0) {
            return "";
        }

        return n.toString();
    }
}