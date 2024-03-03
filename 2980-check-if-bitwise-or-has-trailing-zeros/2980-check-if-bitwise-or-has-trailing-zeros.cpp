class Solution {
public:
    bool hasTrailingZeros(vector<int>& nums) {
        int evenCount = 0;
        
        for(int &num: nums) {
            if(num % 2 == 0)
                evenCount++;
            
            if(evenCount >= 2)
                return true;
        }
        
        return false;
    }
};