class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        // corner cases
        if(n == 0)
            return true;
        if(flowerbed.size() == 1)
            return flowerbed[0] == 0 && n <= 1;
        
        int prev = -1, mid = 0, next = 1;
        for(; mid<flowerbed.size(); mid++) {
            if(flowerbed[mid] == 0) {
                if(prev == -1) {
                    // check if the next positon is 0
                    if(flowerbed[next] == 0) {
                        flowerbed[mid] = 1;
                        n--;
                    }
                    prev++; next++;
                } else if(next == flowerbed.size()) {
                    // check if the prev position is 0
                    if(flowerbed[prev] == 0) {
                        flowerbed[mid] = 1;
                        n--;
                    }
                    prev++;
                } else {
                    if(flowerbed[prev] == 0 && flowerbed[next] == 0) {
                        flowerbed[mid] = 1;
                        n--;
                    }
                    next++; prev++;
                }
            } else {
                next++; prev++;
            }
        }
        
        return n <= 0;
    }
};