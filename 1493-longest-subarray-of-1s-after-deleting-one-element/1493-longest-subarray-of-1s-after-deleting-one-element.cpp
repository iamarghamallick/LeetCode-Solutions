class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int k = 1;
        int start = 0;
        int end = 0;
        
        int ans = 0;
        
        while(end < nums.size()) {
            if(nums[end] == 0) {
                if(k > 0)
                    k--;
                else {
                    while(nums[start] != 0)
                        start++;
                    start++;
                }
            }
            
            ans = max(ans, end - start);
            end++;
        }
        
        return ans;
    }
};