class Solution {
public:
    int maxCoins(vector<int>& piles) {
        sort(piles.begin(), piles.end());
        int n = piles.size()/3;
        int sum = 0;
        int index = piles.size()-2;
        
        for(int i=0; i<n; i++) {
            sum += piles[index];
            index -= 2;
        }
        
        return sum;
    }
};