class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        map<int, vector<int>> map;
        for(int i=0; i<nums.size(); i++) {
            for(int j=0; j<nums[i].size(); j++) {
                map[i+j].push_back(nums[i][j]);
            }
        }
        
        vector<int> ans;
        for(auto iter : map) {
            for(int i=iter.second.size()-1; i>=0; i--) {
                ans.push_back(iter.second[i]);
            }
        }
        
        return ans;
    }
};