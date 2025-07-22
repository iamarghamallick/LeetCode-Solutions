class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> map;
        int maxSum = INT_MIN;
        int currSum = 0;

        int start = 0;
        for(int end = 0; end < n; end++) {
            map[nums[end]]++;
            currSum += nums[end];

            while(map[nums[end]] > 1) {
                map[nums[start]]--;
                if(map[nums[start]] == 0)
                    map.erase(nums[start]);
                currSum -= nums[start];
                start++;
            }

            maxSum = max(maxSum, currSum);
        }

        return maxSum;
    }
};