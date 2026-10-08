class Solution {
    public String removeOuterParentheses(String s) {
        int open = 0;
        String temp = "";
        String ans = "";

        for (char ch : s.toCharArray()) {
            if (ch == '(') {
                open++;
                temp += ch;
            } else {
                open--;
                temp += ch;
            }

            if (open == 0) {
                ans += temp.substring(1, temp.length() - 1);
                temp = "";
            }
        }

        return ans;
    }
}