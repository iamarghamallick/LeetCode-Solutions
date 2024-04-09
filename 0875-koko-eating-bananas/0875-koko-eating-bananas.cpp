class Solution {
public:
    long int findHours(vector<int>& piles, int k) {
        // returns the time she will take if she eats k bananas/hour
        long int time = 0;
        for(int i=0; i<piles.size(); i++) {
            time += ceil((double)piles[i] / (double)k);
        }
        
        return time;
    }
    
    int minEatingSpeed(vector<int>& piles, int h) {
        // answer : minimum int s.t., she can eat all the bananas within h hours
        int k = 1; 
        
        // ans should always lie between [1, maxVal(piles)]
        // find the maxVal
        int maxVal = INT_MIN;
        for(int i=0; i<piles.size(); i++)
            maxVal = max(maxVal, piles[i]);
        
        int low = 1, high = maxVal;
        
        // [low, ... <-- possible --> ..., k, ... <-- not possible -->, high]
        // we apply binary search technique for each possible k
        while(low <= high) {
            int mid = low + (high - low) / 2;
            
            long int timeRequired = findHours(piles, mid);
            
            if(timeRequired <= h) {
                // found a possible ans
                k = mid;
                
                // we go to left dir to look for a minimum ans value (if any)
                high = mid - 1;
            } else {
                // else we go to right dir
                low = mid + 1;
            }
        }
        
        return k;
    }
};