class Solution {
public:
    string removeStars(string s) {
        string ans = "";
        stack<char> st;
        int n = s.size();
        
        for(int i=0; i<n; i++){
            if(s[i] != '*')
                st.push(s[i]);
            else {
                if(st.empty())
                    return "";
                else
                    st.pop();
            }
        }

        while(!st.empty()) {
            ans += st.top();
            st.pop();
        }
        
        reverse(ans.begin(),ans.end());
        return ans;
    }
};