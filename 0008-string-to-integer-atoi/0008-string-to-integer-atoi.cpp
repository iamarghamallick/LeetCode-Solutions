class Solution {
public:
    int myAtoi(string s) {
        int ans = 0, sign = 1;
        bool flag = false; // first valid char is yet to read
        for(int c : s) {
            if(!flag) {
                // check for white-spaces
                if(c == ' ') continue;
                else if(c == '+') sign = 1;
                else if(c == '-') sign = -1;
                else if(isdigit(c)) ans = ans * 10 + (c - '0');
                else
                    return 0;

                flag = true;
            } else if(isdigit(c)) {
                if (ans > (INT_MAX - (c - '0')) / 10) {
                    // Overflow will occur
                    return sign == 1 ? INT_MAX : INT_MIN;
                } else {
                    ans = ans * 10 + (c - '0');
                }
            } else {
                break;
            }
        }

        return ans * sign;
    }
};