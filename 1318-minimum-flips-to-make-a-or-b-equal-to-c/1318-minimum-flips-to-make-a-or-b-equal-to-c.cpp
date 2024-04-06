class Solution {
public:
    int minFlips(int a, int b, int c) {
        int count = 0;
        
        while(a || b || c) {
            int an = a & 1;
            int bn = b & 1;
            int cn = c & 1;
            
            if((an|bn) != cn) {
                if(cn == 1 && an == 0 && bn == 0)
                    count++;
                else if(cn == 0 && an == 1 && bn == 1)
                    count += 2;
                else if(cn == 0 && ((an == 0 && bn == 1) || (an == 1 && bn == 0)))
                    count++;
            }
            
            a >>= 1;
            b >>= 1;
            c >>= 1;
        }
        
        return count;
    }
};