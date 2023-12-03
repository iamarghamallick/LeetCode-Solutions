class Solution {
public:
    int reverse(int x) {
        long rev = 0;
        
        while(x) {
            long rem = x%10;
            rev = rev*10 + rem;
            x /= 10;
        }
        
        return (rev < INT_MIN || rev > INT_MAX) ? 0 : (int)rev;
    }
};