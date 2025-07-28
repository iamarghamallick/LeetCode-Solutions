class Solution {
public:  
    int solve(int i, vector<int>& nums, int currOrVal, int maxOrVal) {
        if(i == nums.size())
            return currOrVal == maxOrVal ? 1 : 0;
        
        return solve(i+1, nums, currOrVal | nums[i], maxOrVal) + 
               solve(i+1, nums, currOrVal, maxOrVal);
    }
    
    int countMaxOrSubsets(vector<int>& nums) {
        int maxOrVal = nums[0];
        for(int i=1; i<nums.size(); i++)
            maxOrVal |= nums[i];
        
        return solve(0, nums, 0, maxOrVal);
    }
};