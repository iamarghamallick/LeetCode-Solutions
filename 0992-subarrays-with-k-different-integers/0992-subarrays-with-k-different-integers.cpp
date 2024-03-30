class Solution {
public:
    int solve(vector<int>& nums, int k) {
        unordered_map<int, int> map;
        int left = 0;
        int totalCount = 0;
        
        for(int right=0; right<nums.size(); right++) {
            map[nums[right]]++;
            
            while(map.size() > k) {
                map[nums[left]]--;
                
                if(map[nums[left]] == 0)
                    map.erase(nums[left]);
                
                left++;
            }
            
            totalCount += right - left + 1;
        }
        
        return totalCount;
    }
    
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return solve(nums, k) - solve(nums, k-1);
    }
};