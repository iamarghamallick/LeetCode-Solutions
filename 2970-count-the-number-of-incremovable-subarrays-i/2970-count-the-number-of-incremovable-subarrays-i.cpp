class Solution {
public:
    int incremovableSubarrayCount(vector<int>& nums) {
        // Initialize variables
        int n = nums.size(), j = n - 1;

        // Find the rightmost index from where the array is not in increasing order upto end
        while (j > 0 and nums[j - 1] < nums[j])
            j--;

        // If the entire array is in increasing order, return the total count of subarrays
        if (j == 0)
            return (n * (n + 1)) / 2;

        // Initialize variables for the final answer calculation
        int ans = n - j + 1, last = -1; 

        // Iterate through the array and count removable subarrays
        for (int i = 0; nums[i] > last; last = nums[i], i++)
            ans += n - (int)(upper_bound(nums.begin() + j, nums.end(), nums[i]) - nums.begin()) + 1;

        // Return the final count of increasing removable subarrays
        return ans;
    }
};