class Solution {
public:
    int minimumSum(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefixMin(n, nums[0]), suffixMin(n, nums[n-1]);
        
        for(int i=1; i<n; i++) {
            prefixMin[i] = min(prefixMin[i-1], nums[i]);
            suffixMin[n-1-i] = min(suffixMin[n-1-i+1], nums[n-1-i]);
        }
        
        int ans = INT_MAX;
        
        for(int j=1; j<n-1; j++) {
            int i = j-1;
            int k = j+1;
            if(nums[j] > prefixMin[i] && nums[j] > suffixMin[k])
                ans = min(ans, prefixMin[i] + nums[j] + suffixMin[k]);
        }
        
        return ans == INT_MAX ? -1 : ans;
    }
};