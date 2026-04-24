class Solution {
    public int furthestDistanceFromOrigin(String moves) {
        int right = 0;
        int dashed = 0;
        for(int i=0; i<moves.length(); i++) {
            if(moves.charAt(i) == '_') {
                dashed++;
            } else if(moves.charAt(i) == 'R') {
                right++;
            } else {
                right--;
            }
        }
        return Math.abs(right) + dashed;
    }
}