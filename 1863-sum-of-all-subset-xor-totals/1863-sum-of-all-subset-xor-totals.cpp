class Solution {
public:
    void generate(int index, vector<int> &nums, vector<int> subset, vector<vector<int>> &subsets) {
        if(index == nums.size()) {
            subsets.push_back(subset);
            return;
        }
        
        subset.push_back(nums[index]);
        generate(index + 1, nums, subset, subsets);
        subset.pop_back();
        
        generate(index + 1, nums, subset, subsets);
    }
    
    int subsetXORSum(vector<int>& nums) {
        // generate all subsets using BACKTRACKING
        vector<vector<int>> subsets;
        generate(0, nums, {}, subsets);
        
        int ans = 0;
        for(auto& arr : subsets) {
            int xorTotal = 0;
            for(int num : arr)
                xorTotal ^= num;
            ans += xorTotal;
        }
        
        return ans;
    }
};