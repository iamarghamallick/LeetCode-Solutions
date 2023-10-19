class Solution {
public:
    string build(string s) {
        stack<char> st;
        for(int i=0; i<s.length(); i++) {
            if(s[i]!='#')
                st.push(s[i]);
            else if(!st.empty())
                    st.pop();
        }
        string str = "";
        while(!st.empty()) {
            str += st.top();
            st.pop();
        }
        return str;
    }

    bool backspaceCompare(string s, string t) {
        s = build(s);
        t = build(t);
        return s==t;
    }
};