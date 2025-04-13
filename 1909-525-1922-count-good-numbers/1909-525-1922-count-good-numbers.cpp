class Solution {
public:
    int MOD = 1000000007;

    long long binaryExponentiation(long long a, long long b) {
        long long res = 1;
        while(b) {
            if(b&1) {
                res = (res * a) % MOD;
            }
            a = (a * a) % MOD;
            b /= 2;
        }

        return res;
    }

    int countGoodNumbers(long long n) {
        return (binaryExponentiation(4, n/2) * binaryExponentiation(5, n - n/2)) % MOD;
    }
};