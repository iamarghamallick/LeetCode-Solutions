class Solution {
    public String removeDuplicateLetters(String s) {
        Stack<Character> st = new Stack<>();
        ArrayList<Boolean> seen = new ArrayList<>(Collections.nCopies(26, false));
        ArrayList<Integer> lastIdx = new ArrayList<>(Collections.nCopies(26, -1));
        int n = s.length();

        for(int i=n-1; i>=0; i--) {
            char ch = s.charAt(i);
            int charIdx = ch - 'a';
            if(lastIdx.get(charIdx) == -1)
                lastIdx.set(charIdx, i);
        }

        for(int i=0; i<n; i++) {
            char ch = s.charAt(i);
            int charIdx = ch - 'a';
            if(!seen.get(charIdx)) {
                while(!st.isEmpty() && ch < st.peek()) {
                    char top = st.peek();
                    int topIdx = top - 'a';
                    if(i < lastIdx.get(topIdx)) {
                        st.pop();
                        seen.set(top - 'a', false);
                    } else {
                        break;
                    }
                }
                st.push(ch);
                seen.set(charIdx, true);
            }
        }

        String ans = "";
        while(!st.isEmpty()) {
            ans = st.peek() + ans;
            st.pop();
        }

        // for(int i=0; i<n; i++) {
        //     char ch = s.charAt(i);
        //     int charIdx = ch - 'a';
        //     System.out.println(lastIdx.get(s.charAt(i) - 'a'));
        // }
        
        return ans;
    }
}