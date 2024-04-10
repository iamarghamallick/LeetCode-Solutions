class Solution {
public:
    int minimumSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();
        int minLength = INT_MAX;
        int sum = 0, count = 0;
        
        for(int i=0; i<n; i++) {
            sum = sum | nums[i];
            count++;
            if(nums[i] > k) {
                minLength = 1;
                break;
            } else if(sum >= k) {
                minLength = min(minLength, count);
                sum = 0;
                i = i - count + 1;
                count = 0;
            }
        }

        return minLength == INT_MAX ? -1 : minLength;
    }
};