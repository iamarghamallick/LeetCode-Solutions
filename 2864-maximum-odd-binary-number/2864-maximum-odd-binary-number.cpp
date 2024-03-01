class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        string ans = "";
        int zeros = 0, ones = 0;
        
        for(int i=0; i<s.size(); i++) {
            if(s[i] == '0') zeros++;
            else ones++;
        }
        
        for(int i=0; i<zeros; i++)
            ans += '0';
        for(int i=0; i<ones-1; i++)
            ans = '1' + ans;
        
        return ans + '1';
    }
};