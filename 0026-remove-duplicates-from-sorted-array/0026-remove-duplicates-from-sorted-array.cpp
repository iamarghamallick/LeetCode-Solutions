class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        for(int i=1; i<n; i++) {
            if(nums[i-1] == nums[i]) {
                nums.erase(nums.begin()+i);
                n--;
                i--;
            }
        }
        return nums.size();
    }
};