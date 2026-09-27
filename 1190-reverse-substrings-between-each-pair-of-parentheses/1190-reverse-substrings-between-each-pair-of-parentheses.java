class Solution {
    public String reverseParentheses(String s) {
        int n = s.length();
        Stack<Integer> st = new Stack<>();
        int[] pair = new int[n];

        for (int i = 0; i < n; i++) {
            if (s.charAt(i) == '(') {
                st.push(i);
            } else if (s.charAt(i) == ')') {
                int idx = st.pop();
                pair[i] = idx;
                pair[idx] = i;
            }
        }

        StringBuilder ans = new StringBuilder();
        for (int i = 0, dir = 1; i < n; i += dir) {
            if (s.charAt(i) == '(' || s.charAt(i) == ')') {
                i = pair[i];
                dir = -dir;
            } else {
                ans.append(s.charAt(i));
            }
        }

        return ans.toString();
    }
}