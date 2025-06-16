class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int maxVal = -1;
        for(int i=0; i<nums.size(); i++) {
            for(int j=i+1; j<nums.size(); j++) {
                maxVal = max(maxVal, nums[j] - nums[i]);
            }
        }

        return maxVal <= 0 ? -1 : maxVal;
    }
};