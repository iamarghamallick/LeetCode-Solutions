class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int right = 0;
        int countDash = 0;
        
        for(char c : moves) {
            if(c == '_')    countDash++;
            else if(c == 'R')   right++;
            else    right--;
        }
        
        return abs(right) + countDash;
    }
};