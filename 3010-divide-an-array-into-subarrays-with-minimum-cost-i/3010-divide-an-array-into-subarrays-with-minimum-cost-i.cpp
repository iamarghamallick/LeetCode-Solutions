class Solution {
public:
    int minimumCost(vector<int>& nums) {
        int min = nums[0];
        sort(nums.begin() + 1, nums.end());
        return min + nums[1] + nums[2];
    }
};