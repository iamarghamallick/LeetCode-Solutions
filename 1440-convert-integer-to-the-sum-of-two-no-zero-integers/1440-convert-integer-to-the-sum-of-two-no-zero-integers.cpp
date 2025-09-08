class Solution {
public:
    bool containsZero(int n) {
        while(n) {
            if(n % 10 == 0) return true;
            n /= 10;
        }

        return false;
    }

    vector<int> getNoZeroIntegers(int n) {
        int a, b;

        for(int num = 1; num < n; num++) {
            a = num;
            b = n - num;

            if(!containsZero(a) && !containsZero(b))
                break;
        }

        return {a, b};
    }
};