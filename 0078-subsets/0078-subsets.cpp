class Solution {
public:
    void generate(int index, vector<int>& nums, vector<int> subset, vector<vector<int>>& subsets) {
        if(index == nums.size()) {
            subsets.push_back(subset);
            return;
        }
        
        subset.push_back(nums[index]);
        generate(index + 1, nums, subset, subsets);
        subset.pop_back();
        
        generate(index + 1, nums, subset, subsets);
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> subsets;
        generate(0, nums, {}, subsets);
        return subsets;
    }
};