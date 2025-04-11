class Solution {
public:
    bool isSymmertic(int n) {
        string s = to_string(n);
        if(s.length() % 2 != 0)
            return false;

        int sum = 0;
        for(int i=0; i<s.length()/2; i++) {
            sum += s[i] - '0';
        }
        for(int i=s.length()/2; i<s.length(); i++) {
            sum -= s[i] - '0';
        }

        return sum == 0;
    }

    int countSymmetricIntegers(int low, int high) {
        int count = 0;
        for(int num = low; num <= high; num++) {
            if(isSymmertic(num))    count++;
        }

        return count;
    }
};