class Solution {
    public String shortestBeautifulSubstring(String s, int k) {
        String ans = "";
        int n = s.length();

        int count = 0;
        int start = 0;

        for (int end = 0; end < n; end++) {

            if (s.charAt(end) == '1') {
                count++;
            }

            // Remove characters until window has at most k ones
            while (count > k) {
                if (s.charAt(start) == '1') {
                    count--;
                }
                start++;
            }

            // Remove unnecessary leading zeroes
            while (start < n && s.charAt(start) == '0') {
                start++;
            }

            if (count == k) {
                String substring = s.substring(start, end + 1);

                if (ans.isEmpty()
                        || substring.length() < ans.length()
                        || (substring.length() == ans.length()
                                && substring.compareTo(ans) < 0)) {
                    ans = substring;
                }
            }
        }

        return ans;
    }
}