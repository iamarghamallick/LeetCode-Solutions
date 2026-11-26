class Solution {
    public boolean canAliceWin(int n) {
        int stones = 10;
        while (stones <= n) {
            n -= stones;
            stones--;
        }
        if (stones % 2 == 0) {
            return false;
        }
        return true;
    }
}