class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        int min = nums[0], max = nums[n-1];
        int ans = 0;
        int i = 0;
        while(i < n) {
            if(nums[i] <= min + k) {
                // ok, continue
            } else {
                ans++;
                min = nums[i];
            }
            i++;
        }
        return ans + 1;
    }
};