class Solution {
    public boolean sumGame(String num) {
        int n = num.length();
        int leftQCount = 0, rightQCount = 0;
        int leftKSum = 0, rightKSum = 0;

        for(int i=0; i<n; i++) {
            char ch = num.charAt(i);
            if(i < n/2) {
                if(ch == '?') leftQCount++;
                else leftKSum += ch - '0';
            } else {
                if(ch == '?') rightQCount++;
                else rightKSum += ch - '0';
            }
        }

        if((leftQCount + rightQCount) % 2 != 0) {
            return true;
        }

        int leftSum = (2 * leftKSum) + (9 * leftQCount);
        int rightSum = (2 * rightKSum) + (9 * rightQCount);

        return leftSum != rightSum;
    }
}