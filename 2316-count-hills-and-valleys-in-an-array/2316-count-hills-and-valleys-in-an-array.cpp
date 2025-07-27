class Solution {
public:
    int countHillValley(vector<int>& nums) {
        int n = nums.size();
        int count = 0;
        
        for(int i=1; i<n-1; i++) {
            if(nums[i] == nums[i-1]) continue;
            int left = i-1, right = i+1;
            while(left >= 0 && nums[left] == nums[i]) left--;
            while(right < n && nums[right] == nums[i]) right++;
            if((0 <= left && left < n && 0 <= right && right < n) &&
                ((nums[i] > nums[left] && nums[i] > nums[right]) || 
                (nums[i] < nums[left] && nums[i] < nums[right])))
                count++;
        }

        return count;
    }
};