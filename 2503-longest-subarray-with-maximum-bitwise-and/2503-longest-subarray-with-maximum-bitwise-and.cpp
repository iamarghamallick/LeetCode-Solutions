class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int maxVal = nums[0];
        for(int num : nums)
            maxVal = max(maxVal, num);
        
        int maxCount = 0;
        int i = 0;
        while(i < nums.size()) {
            int count = 0;
            while(i < nums.size() && nums[i] == maxVal) {
                count++;
                i++;
                maxCount = max(maxCount, count);
            }
            i++;
        }
        
        return maxCount;
    }
};