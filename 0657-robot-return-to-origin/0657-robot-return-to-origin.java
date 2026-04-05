class Solution {
    public boolean judgeCircle(String moves) {
        int left = 0;
        int up = 0;
        char[] arr = moves.toCharArray();
        for(char c : arr) {
            if(c == 'L')    left++;
            else if(c == 'R')   left--;
            else if(c == 'U')   up++;
            else    up--;
        }
        return left == 0 && up == 0;
    }
}