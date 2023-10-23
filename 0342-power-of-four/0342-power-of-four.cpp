class Solution {
public:
    bool isPowerOfFour(int n) {
        // Check if the number is greater than 0 and is a power of 2
        if (n <= 0 || (n & (n - 1)) != 0) {
            return false;
        }

        // Check if the number has an odd number of trailing zeros
        // This indicates it's a power of 4
        return (n & 0x55555555) == n;
    }
};