class Solution {
public:
    string convertToTitle(int n) {
        string result = "";
        while (n > 0) {
            n--;
            int rem = n % 26;
            result = char('A' + rem) + result;
            n /= 26;
        }
        return result;
    }
};