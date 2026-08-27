class Solution {

    String result;

    public String lexGreaterPermutation(String s, String target) {
        int[] freq = new int[26];
        for(char ch: s.toCharArray()) {
            freq[ch - 'a']++;
        }

        result = "";
        
        solve(new StringBuilder(""), freq, target, 0, false);

        return result;
    }

    private boolean solve(StringBuilder curr, int[] freq, String target, int i, boolean greater) {
        if(i == target.length()) {
            if(greater) {
                result = curr.toString();
                return true;
            }

            return false;
        }

        for(int c=0; c<26; c++) {
            if(freq[c] == 0) {
                continue;
            }

            if(greater == false && c < target.charAt(i) - 'a') {
                continue;
            }

            curr.append((char)('a' + c));
            freq[c]--;

            boolean isGreater = greater || c > target.charAt(i) - 'a';

            if(solve(curr, freq, target, i+1, isGreater)) {
                return true;
            }

            if(curr.length() > 0) {
                curr.deleteCharAt(curr.length() - 1);
            }
            freq[c]++;
        }

        return false;
    }
}