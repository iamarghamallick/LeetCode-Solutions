class Solution {
public:
    int minBitFlips(int start, int goal) {
        int count = 0;
        
        while(start || goal) {
            count += (start&1)^(goal&1);
            start /= 2;
            goal /= 2;
        }
        
        return count;
    }
};