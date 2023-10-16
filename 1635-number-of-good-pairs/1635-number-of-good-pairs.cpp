class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int pairs = 0;
        for(int i=nums.size()-1; i>=0; i--) {
            for(int j=i-1; j>=0; j--) {
                if(nums[i] == nums[j])
                    pairs++;
            }
        }
        return pairs;
    }
};