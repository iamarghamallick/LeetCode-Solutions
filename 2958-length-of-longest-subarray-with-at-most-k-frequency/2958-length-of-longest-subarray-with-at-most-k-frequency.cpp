class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int start = -1;
        int end = 0;
        int ans = 0;
        unordered_map<int, int> map;
        
        for(; end<nums.size(); end++) {
            map[nums[end]]++;
            
            while(map[nums[end]] > k) {
                start++;
                map[nums[start]]--;
            }
            
            ans = max(ans, end - start);
        }
        
        return ans;
    }
};