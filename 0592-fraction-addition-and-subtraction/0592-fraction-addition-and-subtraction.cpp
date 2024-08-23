class Solution {
public:
    string fractionAddition(string exp) {
        int num = 0;
        int denum = 1;
        int n = exp.size();
        int i = 0;
        
        while(i < n) {
            int currNum = 0;
            int currDenum = 0;
            bool isNeg = false;
            
            // process the sign
            if(exp[i] == '+' || exp[i] == '-') {
                if(exp[i] == '-')
                    isNeg = true;
                i++;
            }
            
            // process the numerator
            while(i < n && isdigit(exp[i])) {
                int val = exp[i] - '0';
                currNum = currNum * 10 + val;
                i++;
            }
            
            // skip the division sign
            i++;
            
            // process the denominator
            while(i < n && isdigit(exp[i])) {
                int val = exp[i] - '0';
                currDenum = currDenum * 10 + val;
                i++;
            }
            
            if(isNeg)   currNum *= -1;
            
            // process the fraction
            num = num * currDenum + denum * currNum;
            denum = denum * currDenum;
        }
        
        int gcd = abs(findGCD(num, denum));
        
        num /= gcd;
        denum /= gcd;
        
        return to_string(num) + "/" + to_string(denum);
    }

private:
    int findGCD(int a, int b) {
        if(a == 0)
            return b;
        return findGCD(b % a, a);
    }
};