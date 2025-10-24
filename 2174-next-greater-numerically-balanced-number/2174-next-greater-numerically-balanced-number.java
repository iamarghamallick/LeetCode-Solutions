class Solution {
    public int nextBeautifulNumber(int n) {
        for(int num = n+1; num <= 1224444; num++)
            if(isBalanced(num))
                return num;

        return 1224444;
    }

    private boolean isBalanced(int n) {
        int[] freq = new int[10];

        while(n > 0) {
            int d = n % 10;
            freq[d] += 1;
            n /= 10;
        }

        for(int i=0; i<10; i++)
            if(freq[i] > 0 && freq[i] != i)
                return false;

        return true;
    }
}