class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, bool> map;
        for(int num : nums) map[num] = false;
        int toDel = 0;
        for(int i=n-1; i>=0; i--) {
            if(map[nums[i]]) {
                // duplicate element found
                toDel = i+1;
                break;
            } else {
                map[nums[i]] = true;
            }
        }

        return toDel % 3 == 0 ? toDel / 3 : toDel / 3 + 1;
    }
};