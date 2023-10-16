class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        bool flagI = false;
        bool flagD = false;
        for(int i=0; i<nums.size()-1; i++) {
            if(nums[i] == nums[i+1])
                continue;
            else if(nums[i]<nums[i+1]) {
                if(!flagD)
                    flagI = true;
                else
                    return false;
            } else {
                if(!flagI)
                    flagD = true;
                else
                    return false;
            }
        }
        return true;
    }
};