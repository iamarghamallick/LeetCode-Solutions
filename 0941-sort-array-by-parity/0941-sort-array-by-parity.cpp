class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        vector<int> arr(nums.size());
        int left = 0;
        int right = nums.size()-1;
        while(left <= right) {
            if(nums[left]%2 != 0 && nums[right]%2 == 0) {
                arr[left] = nums[right];
                arr[right] = nums[left];
                left++; right--;
            } else if(nums[left]%2 == 0) {
                arr[left] = nums[left];
                left++;
            } else {
                arr[right] = nums[right];
                right--;
            }
        }
        return arr;
    }
};