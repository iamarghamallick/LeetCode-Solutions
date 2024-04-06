class Solution {
public:    
    string minRemoveToMakeValid(string s) {
        int n = s.length();
        stack<int> st;
        
        for(int i=0; i<n; i++) {
            if(s[i] == '(')
                st.push(i);
            else if(s[i] == ')') {
                if(st.empty()) {
                    s.erase(i, 1);
                    i--;
                } else 
                    st.pop();
            }
        }
        
        while(!st.empty()) {
            int i = st.top();
            s.erase(i, 1);
            st.pop();
        }
        
        return s;
    }
};