class Solution {
public:
    string makeGood(string s) {
        int n = s.length();
        
        if(n == 1)
            return s;
        
        int i=1;
        for( ; i<n; i++) {
            if((s[i] - '0' + 32) == (s[i-1] - '0') || (s[i-1] - '0') == (s[i] - '0' - 32)) {
                s.erase(i-1, 2);
                break;
            }
        }
        
        if(i < n)
            return makeGood(s);
        
        return s;
    }
};