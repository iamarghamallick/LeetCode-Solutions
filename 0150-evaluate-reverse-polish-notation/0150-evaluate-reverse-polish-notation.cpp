class Solution {
public:
    bool isOperator(string s) {
        return s == "+" || s == "-" || s == "*" || s == "/";
    }
    
    int eval(int n1, int n2, string op) {
        if(op == "+")   return n1 + n2;
        if(op == "-")   return n1 - n2;
        if(op == "*")   return n1 * n2;
        if(op == "/")   return n1 / n2;
        
        return 0;
    }
    
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        
        for(int i=0; i<tokens.size(); i++) {
            // if tokens[i] is an operator ( +, -, *, /)
            if(isOperator(tokens[i])) {
                int n2 = st.top();  st.pop();
                int n1 = st.top();  st.pop();
                int ans = eval(n1, n2, tokens[i]);
                st.push(ans);
            } else {
                int n = stoi(tokens[i]);
                st.push(n);
            }
        }
        
        return st.top();
    }
};