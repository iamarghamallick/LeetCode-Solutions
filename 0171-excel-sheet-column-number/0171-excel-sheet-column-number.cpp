class Solution {
public:
    int titleToNumber(string colTitle) {
        int base = 26;
        long long power = 1;
        int ans = 0;

        for(int i=colTitle.length()-1; i>=0; i--) {
            int val = colTitle[i] - 'A' + 1;
            ans += val * power;
            power *= base;
        }

        return ans;
    }
};