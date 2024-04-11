class Solution {
public:
    bool judgeCircle(string moves) {
        int left = 0;
        int up = 0;
        
        for(char c : moves) {
            if(c == 'L')    left++;
            else if(c == 'R')   left--;
            else if(c == 'U')   up++;
            else    up--;
        }
        
        return left == 0 && up == 0;
    }
};