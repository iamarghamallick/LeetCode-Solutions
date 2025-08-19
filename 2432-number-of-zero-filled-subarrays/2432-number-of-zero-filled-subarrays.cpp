class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long ans = 0;
        int zeros = 0;

        for(int i=0; i<nums.size(); i++) {
            if(nums[i] == 0) {
                zeros++;
                ans += zeros;
            } else {
                zeros = 0;
            }
        }
        
        return ans;
    }
};