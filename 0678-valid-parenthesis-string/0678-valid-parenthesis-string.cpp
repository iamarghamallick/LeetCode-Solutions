class Solution {
public:
    bool checkValidString(string s) {
        int n = s.length();
        stack<int> st1; // storing indices of open brackets
        stack<int> st2; // storing indices of stars
        
        for(int i=0; i<n; i++) {
            if(s[i] == '(')
                st1.push(i);
            
            else if(s[i] == '*')
                st2.push(i);
            
            else if(s[i] == ')') {
                // if there are open brackets available, use it to balance the closing bracket
                if(!st1.empty())
                    st1.pop();
                // else use a star to balance the closing bracket
                else if(!st2.empty())
                    st2.pop();
                // else unmatched ')' and no star available
                else 
                    return false;
            }
        }
        
        while(!st1.empty() && !st2.empty()) {
            // if an open bracket appears after a star, it cannot be balanced, return false
            if(st1.top() > st2.top())
                return false;
            
            // otherwise
            st1.pop();
            st2.pop();
        }
        
        return st1.empty();
    }
};