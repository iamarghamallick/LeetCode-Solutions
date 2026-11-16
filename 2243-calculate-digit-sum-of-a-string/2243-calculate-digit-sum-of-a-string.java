class Solution {
    public String digitSum(String s, int k) {
        while (s.length() > k) {
            StringBuilder sb = new StringBuilder();
            int i = 0;
            int sum = 0;

            while (i < s.length()) {
                sum += (s.charAt(i) - '0');
                if ((i + 1) % k == 0 || i == s.length() - 1) {
                    sb.append(String.valueOf(sum));
                    sum = 0;
                }
                i++;
            }
            s = sb.toString();
        }

        return s;
    }
}