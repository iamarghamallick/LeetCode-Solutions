class Solution {
    public int minCost(String colors, int[] neededTime) {
        int ans = 0;
        int prev = 0;
        for(int i=1; i<colors.length(); i++) {
            char ch = colors.charAt(i);
            if(colors.charAt(prev) == ch) {
                if(neededTime[prev] < neededTime[i]) {
                    ans += neededTime[prev];
                    prev = i;
                } else {
                    ans += neededTime[i];
                }
            } else {
                prev = i;
            }
        }
        return ans;
    }
}