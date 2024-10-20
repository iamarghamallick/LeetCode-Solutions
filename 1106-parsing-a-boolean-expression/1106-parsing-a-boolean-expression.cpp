class Solution {
public:
    string evaluate(string exp, char op) {
        if(op == '&')
            return exp.contains("f") ? "f" : "t";
        if(op == '|')
            return exp.contains("t") ? "t" : "f";
        if(op == '!')
            return exp == "t" ? "f" : "t";
        return "";
    }
    
    bool parseBoolExpr(string exp) {
        int n = exp.size();
        int i = 0;
        stack<string> st;
        stack<char> op;
        
        for(char c : exp) {
            if(c == '&' || c == '|' || c == '!')
                op.push(c);
            
            else if(c == '(')
                st.push("");
            
            else if(c == 't' || c == 'f') {
                if(!st.empty())
                    st.top() += c;
            }
            
            else if(c == ')') {
                string subExp = st.top();
                st.pop();
                
                char oper = op.top();
                op.pop();
                
                string res = evaluate(subExp, oper);
                
                if(!st.empty()) st.top() += res;
                else    st.push(res);
            }
        }
        
        return st.top() == "t";
    }
};