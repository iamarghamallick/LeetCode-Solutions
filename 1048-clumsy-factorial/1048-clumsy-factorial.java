class Solution {
    public int clumsy(int n) {
        int ans = 0, extra = 0;
        while(n >= 1) {
            int temp = n;
            n--;
            if(n >= 1) temp *= n;
            n--;
            if(n >= 1) temp /= n;
            n--;
            if(n >= 1) extra += n;
            n--;

            if(ans == 0) ans = temp;
            else ans -= temp;
        }

        return ans + extra;
    }
}