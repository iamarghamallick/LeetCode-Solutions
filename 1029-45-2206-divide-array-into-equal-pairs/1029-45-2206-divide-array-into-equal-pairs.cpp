class Solution {
public:
    bool divideArray(vector<int>& nums) {
        unordered_map<int, int> map;
        for(int num : nums) map[num]++;
        for(auto iter = map.begin(); iter != map.end(); iter++)
            if(iter->second % 2 == 1)
                return false;
        
        return true;
    }
};