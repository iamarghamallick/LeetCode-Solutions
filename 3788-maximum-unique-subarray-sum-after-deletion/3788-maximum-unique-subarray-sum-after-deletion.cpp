class Solution {
public:
    int maxSum(vector<int>& nums) {
        int maxVal = INT_MIN;
        for(int num : nums) maxVal = max(maxVal, num);
        if(maxVal <= 0) return maxVal;

        unordered_set<int> set(nums.begin(), nums.end());
        
        int ans = 0;
        for (const auto& num : set) {
            if(num > 0) ans += num;
        }

        return ans;
    }
};