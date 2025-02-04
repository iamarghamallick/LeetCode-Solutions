class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int ans = nums[0], temp = nums[0];
        int index = 1;
        while(index < nums.size()) {
            if(nums[index-1] < nums[index]) {
                temp += nums[index];
                ans = max(ans, temp);
            } else {
                temp = nums[index];
            }
            index++;
        }

        return ans;
    }
};