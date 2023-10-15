class Solution {
public:
    int mySqrt(int x) {
        if(x==0 || x==1) return x;
        double sr = x/2;
        double temp;
        do {
            temp = sr;
            sr = (temp + (x/temp)) / 2;
        } while(temp-sr != 0);
        return (int)sr;
    }
};