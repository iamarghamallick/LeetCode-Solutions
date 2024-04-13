class Solution {
public:
    int arithmeticTriplets(vector<int>& nums, int diff) {
        map<int, int> map;
        int count = 0;
        for(int i=0; i<nums.size(); i++)
            map[nums[i]]++;

        for(int i = 0; i < nums.size(); i++)
            if (map[nums[i] + diff] && map[nums[i] + (diff * 2)]) 
                count++;
        
        return count;
    }
};