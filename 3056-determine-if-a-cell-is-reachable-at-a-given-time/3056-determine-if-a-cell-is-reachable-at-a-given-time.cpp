class Solution {
public:
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
        int w = abs(sx-fx);
        int h = abs(sy-fy);
        if(w==0 && h==0 && t==1)    
            return false;

        return t >= max(w, h);
    }
};