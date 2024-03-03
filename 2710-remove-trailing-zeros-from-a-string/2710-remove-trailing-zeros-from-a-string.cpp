class Solution {
public:
    string removeTrailingZeros(string num) {
        string ans = "";
        
        int flag = 0;
        for(int i=num.size()-1; i>=0; i--) {
            if(flag)
                ans = num[i] + ans;
            else if(num[i] != '0') {
                flag = 1;
                ans = num[i] + ans;
            }
        }
        
        return ans;
    }
};