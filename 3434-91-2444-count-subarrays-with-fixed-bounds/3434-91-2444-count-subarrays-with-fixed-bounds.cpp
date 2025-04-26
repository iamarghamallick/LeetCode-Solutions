class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        long long answer = 0; // Variable to store the final count of subarrays
        int lastMinIndex = -1; // Index of the last occurrence of minK
        int lastMaxIndex = -1; // Index of the last occurrence of maxK
        int lastIndexOutsideRange = -1; // Index of the last number that is outside the [minK, maxK] range

        // Iterate through the array to count valid subarrays
        for (int i = 0; i < nums.size(); ++i) {
            // If current element is outside the [minK, maxK] range, update the index
            if (nums[i] < minK || nums[i] > maxK) lastIndexOutsideRange = i;
            // If current element equals minK, update the index of the last occurrence of minK
            if (nums[i] == minK) lastMinIndex = i;
            // If current element equals maxK, update the index of the last occurrence of maxK
            if (nums[i] == maxK) lastMaxIndex = i;

            // Count subarrays ending at index i which have minK and maxK within them
            answer += max(0, min(lastMinIndex, lastMaxIndex) - lastIndexOutsideRange);
        }

        return answer; // Return the total count of valid subarrays
    }
};