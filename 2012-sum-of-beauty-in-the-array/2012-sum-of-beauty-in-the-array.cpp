class Solution {
public:
    int sumOfBeauties(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefix(n, nums[0]), suffix(n, nums[n-1]);
        for(int i=1; i<n; i++) {
            prefix[i] = max(prefix[i-1], nums[i]);
            suffix[n-1-i] = min(suffix[n-1-i+1], nums[n-1-i]);
        }
        
        int ans = 0;
        
        for(int i=1; i<n-1; i++) {
            int j = i-1;
            int k = i+1;
            
            if(prefix[j] < nums[i] && nums[i] < suffix[k])
                ans += 2;
            else if(nums[i-1] < nums[i] && nums[i] < nums[i+1])
                ans += 1;
        }
        
        return ans;
    }
};