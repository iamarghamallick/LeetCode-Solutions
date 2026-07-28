class Solution {
    public String smallestPalindrome(String s) {
        int n = s.length() / 2;
        char[] map = new char[26];

        for (int i=0; i<n; i++) {
            map[s.charAt(i) - 'a'] += 1;
        }

        StringBuilder left = new StringBuilder();
        for (int i = 0; i < 26; i++) {
            if (map[i] > 0) {
                left.append(String.valueOf((char) (i + 'a')).repeat(map[i]));
            }
        }

        String mid = s.length() % 2 != 0 ? String.valueOf(s.charAt(n)) : "";

        String right = new StringBuilder(left).reverse().toString();

        return left.toString() + mid + right;
    }
}