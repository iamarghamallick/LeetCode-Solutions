class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int count = 0;
        
        int i = 0;
        while(i < nums.size()) {
            if(nums[i] == 0) {
                nums.erase(nums.begin() + i);
                count++;
            } else i++;
        }
        
        while(count--)
            nums.push_back(0);
    }
};