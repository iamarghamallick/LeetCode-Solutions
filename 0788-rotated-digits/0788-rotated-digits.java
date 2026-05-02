class Solution {
    public int rotatedDigits(int n) {
        int[] dp = new int[n+1];
        int count = 0;
        for(int i=0; i<=n; i++) {
            if(i <= 9) {
                if(i==0 || i==1 || i==8) {
                    dp[i] = 0;
                } else if(i==2 || i==5 || i==6 || i==9) {
                    dp[i] = 1;
                    count++;
                } else {
                    dp[i] = -1;
                }
            } else {
                int q = i / 10;
                int r = i % 10;

                if((dp[q] == 1 && dp[r] == 0) || (dp[q] == 0 && dp[r] == 1)) {
                    dp[i] = 1;
                    count++;
                } else if(dp[q] == -1 || dp[r] == -1) {
                    dp[i] = -1;
                } else if(dp[q] == 0 && dp[r] == 0) {
                    dp[i] = 0;
                } else {
                    dp[i] = 1;
                    count++;
                }
            }
        }
        return count;
    }
}