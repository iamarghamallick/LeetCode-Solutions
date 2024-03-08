class Solution {
public:
    int missingInteger(vector<int>& nums) {
        vector<int> a(52, 0);
        for(int &num : nums)
            a[num] = 1;
        
        int sum = nums[0];
        for(int i=1; i<nums.size(); i++) {
            if(nums[i] == nums[i-1] + 1)
                sum += nums[i];
            else break;
        }
        
        if(sum > 51)    return sum;
        
        int ans = sum;
        for(int i=ans; i<=51; i++) {
            if(a[i] != 1) {
                ans = i;
                break;
            }
        }
        
        return ans;
    }
};