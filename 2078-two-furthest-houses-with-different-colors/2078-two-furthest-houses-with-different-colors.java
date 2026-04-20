class Solution {
    public int maxDistance(int[] colors) {
        int ans = 0;
        for(int i=0; i<colors.length; i++) {
            for(int j=i; j<colors.length; j++) {
                if(colors[i] != colors[j]) {
                    ans = Math.max(ans, Math.abs(i - j));
                }
            }
        }
        return ans;
    }
}