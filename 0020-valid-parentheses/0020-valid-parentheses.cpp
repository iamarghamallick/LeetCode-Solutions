class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(int i=0; i<s.length(); i++) {
            if(s[i]=='(' || s[i]=='{' || s[i]=='[') {
                if(s[i]=='(') st.push(')');
                if(s[i]=='{') st.push('}');
                if(s[i]=='[') st.push(']');
            } else {
                if(!st.empty() && st.top()==s[i]) {
                    st.pop();
                } else {
                    return false;
                }
            }
            if(i == s.length()-1) {
                if(!st.empty()) return false;
            }
        }
        return true;
    }
};