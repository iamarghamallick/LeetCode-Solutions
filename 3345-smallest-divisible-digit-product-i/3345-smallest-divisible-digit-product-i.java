class Solution {
    public int smallestNumber(int n, int t) {
        while(pod(n) % t != 0) {
            n++;
        }
        return n;
    }

    private int pod(int n) {
        int prod = 1;
        while(n > 0) {
            prod *= n % 10;
            n /= 10;
        }
        return prod;
    }
}