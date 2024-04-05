class Solution {
public:
    int fib(int n) {
        if(n == 0)  return 0;
        if(n == 1)  return 1;
        
        int T0 = 0, T1 = 1;
        
        for(int num = 2; num <= n; num++) {
            int Tn = T1 + T0;
            T0 = T1;
            T1 = Tn;
        }
        
        return T1;
    }
};