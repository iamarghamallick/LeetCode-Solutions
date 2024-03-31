class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        unordered_map<int, int> v;
        for(int i=0; i<nums.size(); i++) {
            if(nums[i] <= k)
                v[k - nums[i]]++;
        }
        
        int count = 0;
        for(int i=0; i<nums.size(); i++) {
            if(nums[i] <= k){
                if(v[nums[i]]) {
                    count++;
                    v[nums[i]]--;
                }
            }
        }
        
        return count / 2;
    }
};