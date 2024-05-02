class Solution {
public:
    int findMaxK(vector<int>& nums) {
        vector<bool> v(1001, false);
        for(int num : nums)
            if(num > 0)
                v[num] = true;
        
        int ans = -1;
        for(int num : nums)
            if(num < 0 && v[abs(num)])
                ans = max(ans, abs(num));
        
        return ans;
    }
};