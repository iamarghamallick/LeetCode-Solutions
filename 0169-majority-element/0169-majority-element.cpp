class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> f;

        for(auto i : nums){
            ++f[i];
        }

        for(auto i : f){
            if(i.second > nums.size() / 2){
                return i.first;
            }
        }

        return 0;
    }
};