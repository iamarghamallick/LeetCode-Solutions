class Solution {
public:
    int getNumberOfBits(long long val) {
        int count = 0;
        while (val) {
            if (val & 1) count++;
            val >>= 1;
        }
        return count;
    }

    int makeTheIntegerZero(int num1, int num2) {
        for (int t = 1; t <= 60; t++) {
            long long val = 1LL * num1 - 1LL * t * num2; // prevent overflow
            if (val < 0) return -1;  // avoid negative case
            int bits = getNumberOfBits(val);
            if (bits <= t && t <= val) return t; // add condition t <= val
        }
        return -1;
    }
};