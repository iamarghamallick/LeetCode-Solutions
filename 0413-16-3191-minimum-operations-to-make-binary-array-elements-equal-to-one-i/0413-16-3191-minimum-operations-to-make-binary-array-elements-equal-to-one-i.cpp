class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size(), count = 0;

        for(int i=0; i<=n-3; i++) {
            if(nums[i] == 0) {
                nums[i] = 1;
                nums[i+1] = nums[i+1] == 0 ? 1 : 0;
                nums[i+2] = nums[i+2] == 0 ? 1 : 0;
                count++;
            }
        }

        return (nums[n-1] == 0 || nums[n-2] == 0 || nums[n-3] == 0) ? -1 : count;
    }
};