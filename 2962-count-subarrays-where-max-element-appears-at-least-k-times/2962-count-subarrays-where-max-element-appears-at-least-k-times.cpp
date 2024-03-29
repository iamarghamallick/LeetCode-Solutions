class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int maxElem = *max_element(nums.begin(), nums.end());
        long long ans = 0;
        int start = 0;
        
        for(int end=0; end<nums.size(); end++) {
            if(nums[end] == maxElem)    k--;
            
            while(!k) {
                if(nums[start] == maxElem)  k++;
                start++;
            }
            
            ans += start;
        }
        
        return ans;
    }
};