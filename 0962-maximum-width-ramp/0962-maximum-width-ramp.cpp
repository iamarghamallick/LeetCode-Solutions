class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        int n = nums.size();
        vector<int> indi(n);
        for(int i=0; i<n; i++)   indi[i] = i;
        sort(indi.begin(), indi.end(), [&](int i, int j) {
            return nums[i] != nums[j] ? nums[i] < nums[j] : i < j;
        });
        
        int minIndex = n, maxWidth = 0;
        for(int i=0; i<n; i++) {
            maxWidth = max(maxWidth, indi[i] - minIndex);
            minIndex = min(minIndex, indi[i]);
        }
        
        return maxWidth;
    }
};