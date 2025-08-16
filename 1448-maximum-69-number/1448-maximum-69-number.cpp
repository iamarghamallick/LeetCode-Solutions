class Solution {
public:
    int maximum69Number (int num) {
        vector<int> digits;
        while(num) {
            digits.push_back(num % 10);
            num /= 10;
        }

        int i = digits.size()-1;
        while(i >= 0) {
            if(digits[i] == 6) {
                digits[i] = 9;
                break;
            }
            i--;
        }

        int ans = 0;
        i = digits.size()-1;
        while(i >= 0) {
            ans = ans * 10 + digits[i];
            i--;
        }

        return ans;
    }
};