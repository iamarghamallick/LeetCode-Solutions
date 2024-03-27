class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if(k <= 1)  return 0;
        
        int count = 0;
        int left = 0, right = 0;
        int pro = 1;
        
        while(right < nums.size()) {
            pro *= nums[right];
            
            while(pro >= k)
                pro /= nums[left++];
            
            count += right - left + 1;
            right++;
        }
        
        return count;
    }
};