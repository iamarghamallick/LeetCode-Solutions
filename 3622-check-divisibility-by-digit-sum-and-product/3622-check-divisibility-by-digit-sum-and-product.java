class Solution {
    public boolean checkDivisibility(int n) {
        int[] sumAndProduct = getSumAndProduct(n);
        return n % (sumAndProduct[0] + sumAndProduct[1]) == 0;        
    }

    private int[] getSumAndProduct(int n) {
        int[] ans = {0, 1};
        while(n > 0) {
            ans[0] += n % 10;
            ans[1] *= n % 10;
            n /= 10;
        }
        return ans;
    }
}