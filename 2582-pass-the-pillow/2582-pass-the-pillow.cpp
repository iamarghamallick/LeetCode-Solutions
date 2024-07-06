class Solution {
public:
    int passThePillow(int n, int time) {
        int i = 1;
        int dir = 1;
        
        while(time) {
            if(i == n)  dir = -1;
            if(i == 1)  dir = 1;
            i += 1 * dir;
            time--;
        }
        
        return i;
    }
};