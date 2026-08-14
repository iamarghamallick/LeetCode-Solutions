class Solution {
    public int maximumLengthSubstring(String s) {
        int[] map = new int[26];
        int maxLen = 0;
        int i = 0;
        for(int j=0; j<s.length(); j++) {
            char ch = s.charAt(j);
            map[ch - 'a'] += 1;
            while(map[ch - 'a'] > 2) {
                map[s.charAt(i) - 'a'] -= 1;
                i++;
            }
            maxLen = Math.max(maxLen, j - i + 1);
        }
        return maxLen;
    }
}