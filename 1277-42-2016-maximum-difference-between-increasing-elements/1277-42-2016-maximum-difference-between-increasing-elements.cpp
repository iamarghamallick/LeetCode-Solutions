class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        // int maxVal = -1;
        // for(int i=0; i<nums.size(); i++) {
        //     for(int j=i+1; j<nums.size(); j++) {
        //         maxVal = max(maxVal, nums[j] - nums[i]);
        //     }
        // }

        // return maxVal <= 0 ? -1 : maxVal;

        // OPTIMAL SOLUTION
        int n = nums.size();
        int ans = -1, premin = nums[0];
        for (int i = 1; i < n; ++i) {
            if (nums[i] > premin) {
                ans = max(ans, nums[i] - premin);
            } else {
                premin = nums[i];
            }
        }
        return ans;
    }
};