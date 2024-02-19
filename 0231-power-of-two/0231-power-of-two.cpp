class Solution {
public:
    bool isPowerOfTwo(int n) {
        return n and !(n & (n - 1LL));
    }
};