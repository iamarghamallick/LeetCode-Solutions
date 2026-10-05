class Solution {
    public boolean isHappy(int n) {
        HashSet<Integer> set = new HashSet<>();

        while (n != 1) {
            set.add(n);

            n = compute(n);

            if (set.contains(n)) {
                return false;
            }
        }

        return true;
    }

    private int compute(int n) {
        int ans = 0;

        while (n > 0) {
            int d = n % 10;
            ans += d * d;
            n /= 10;
        }

        return ans;
    }
}