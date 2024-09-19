class Solution {
public:
    vector<int> diffWaysToCompute(string exp) {
        vector<int> res;
        
        if(exp.size() == 0)
            return res;
        if(exp.size() == 1) {
            res.push_back(stoi(exp));
            return res;
        }
        if(exp.size() == 2 && isdigit(exp[0])) {
            res.push_back(stoi(exp));
            return res;
        }
        
        for(int i=0; i<exp.size(); i++) {
            char curr = exp[i];
            if(isdigit(curr))
                continue;
            
            vector<int> leftRes = diffWaysToCompute(exp.substr(0, i));
            vector<int> rightRes = diffWaysToCompute(exp.substr(i+1));
            
            for(int leftVal : leftRes) {
                for(int rightVal : rightRes) {
                    int ans = 0;
                    
                    switch(curr) {
                        case '+':
                            ans = leftVal + rightVal;
                            break;
                        case '-':
                            ans = leftVal - rightVal;
                            break;
                        case '*':
                            ans = leftVal * rightVal;
                            break;
                    }
                    
                    res.push_back(ans);
                }
            }
        }
        
        return res;
    }
};