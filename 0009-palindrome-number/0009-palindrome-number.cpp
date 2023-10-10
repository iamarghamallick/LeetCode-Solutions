class Solution {
public:
    bool isPalindrome(long long x) {
        long long temp = x;
        long long rev = 0;
        while(temp>0) {
            long long rem = temp % 10;
            rev = rev * 10 + rem;
            temp /= 10;
        }
        return rev == x;
    }
};