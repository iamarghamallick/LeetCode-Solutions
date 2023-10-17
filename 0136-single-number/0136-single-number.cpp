class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_set<int> s;
        for(int i=0; i<nums.size(); i++) {
            if(s.find(nums[i]) == s.end())
                s.insert(nums[i]);
            else 
                s.erase(s.find(nums[i]));
        }
        return *(s.begin());
    }
};