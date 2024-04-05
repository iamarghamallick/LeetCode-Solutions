class Solution {
public:
    string solve(string str, int count) {
        string ans = "";
        for(int i=0; i<count; i++)
            ans += str;
        
        return ans;
    }
    
    string decodeString(string s) {
        int n = s.size();
        stack<char> st;
        
        for(int i=0; i<n; i++) {
            if(s[i] == ']') {
                string str = "";
                
                while(!st.empty() && st.top() != '[') {
                    str += st.top();
                    st.pop();
                }
                st.pop();
                
                reverse(str.begin(), str.end());
                
                string count = "";
                while(!st.empty() && isdigit(st.top())) {
                    count += st.top();
                    st.pop();
                }
                
                reverse(count.begin(), count.end());
                
                stringstream ss;
                ss << count;
                int num = 0;
                ss >> num;
                
                str = solve(str, num);
                
                for(int j=0; j<str.size(); j++)
                    st.push(str[j]);
                
            } else {
                st.push(s[i]);
            }
        }
        
        string ans = "";
        while(!st.empty()) {
            ans = st.top() + ans;
            st.pop();
        }
        
        return ans;
    }
};