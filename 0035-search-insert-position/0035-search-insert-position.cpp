class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int left = 0;
        int expIdx;
        int right = nums.size()-1;
        while(left <= right) {
            int mid = (left+right)/2;
            if(target == nums[mid]) return mid;
            if(target < nums[mid]) {
                right = mid-1;
                expIdx = mid;
            } else {
                left = mid+1;
                expIdx = mid+1;
            }
        }
        return expIdx;
    }
};