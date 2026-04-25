class Solution {
    public List<String> generateParenthesis(int n) {
        List<String> ans = new ArrayList<>();
        generate("", ans, 2 * n);
        return ans;
    }

    private void generate(String s, List<String> ans, int n) {
        if(s.length() == n) {
            if(isValid(s)) {
                ans.add(s);
            }
            return;
        }

        s = s + "(";
        generate(s, ans, n);
        s = s.substring(0, s.length()-1);
        
        s = s + ")";
        generate(s, ans, n);
        s = s.substring(0, s.length()-1);
    }

    private boolean isValid(String s) {
        Stack<Character> st = new Stack<>();
        char[] arr = s.toCharArray();
        for(char c : arr) {
            if(c == '(') st.push(c);
            if(c == ')') {
                if(st.empty()) {
                    return false;
                } else {
                    st.pop();
                }
            }
        }
        return st.empty();
    }
}