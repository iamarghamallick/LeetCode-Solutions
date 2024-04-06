class Solution {
public:
    int binarySearch(vector<int>& potions, double key) {
        int left = 0, right = potions.size() - 1;

        while(left < right) {
            int mid = left + (right - left) / 2;
            if(potions[mid] >= key)
                right = mid;
            else
                left = mid + 1;
        }
        
        return key <= potions[left] ? left : left + 1;
    }
    
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        int n = spells.size();
        int m = potions.size();
        
        sort(potions.begin(), potions.end());
        
        vector<int> ans(n, 0);
        
        for(int i=0; i<n; i++) {
            double key = success / (double)spells[i];
            
            int count = 0;
            int startIdx = binarySearch(potions, key);
            
            if(startIdx < m)    count = m - startIdx;
            
            ans[i] = count;
        }
        
        return ans;
    }
};