class Solution {
public:
    int minimumPushes(string word) {
        int l = word.size();
        if(l <= 8)    return l;
        if(l <= 16)   return 8 + 2*(l-8);
        if(l <= 24)   return 24 + 3*(l-16);
        
        return 48 + 4 * (l-24);
    }
};