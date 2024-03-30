class Solution {
public:
    string reverseWords(string s) {
        stack<string> st;
        string curr = "";
        for(int i=0; i<s.size(); i++) {
            if(s[i] == ' ') {
                if(curr.size() >= 1) {
                    st.push(curr);
                    curr = "";
                }
            } else if(s[i] != ' ') {
                curr += s[i];
            }
        }
        if(curr.size() >= 1) {
            st.push(curr);
            curr = "";
        }
        
        string ans = "";
        while(!st.empty()) {
            ans += st.top();
            st.pop();
            if(!st.empty())
                ans += " ";
        }
        
        return ans;
    }
};