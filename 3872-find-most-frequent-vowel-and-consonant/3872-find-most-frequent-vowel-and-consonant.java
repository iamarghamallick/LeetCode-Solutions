class Solution {
    public int maxFreqSum(String s) {
        int[] freq = new int[26];
        char[] arr = s.toCharArray();

        for(char ch : arr)
            freq[ch - 'a'] += 1;

        int maxV = 0;
        int maxC = 0;
        
        for(int i=0; i<26; i++) {
            char ch = (char) ('a' + i);
            if(ch == 'a' || ch == 'e' || ch == 'i' ||
               ch == 'o' || ch == 'u') {
                maxV = Math.max(maxV, freq[i]);
            } else {
                maxC = Math.max(maxC, freq[i]);
            }
        }

        return maxV + maxC;
    }
}