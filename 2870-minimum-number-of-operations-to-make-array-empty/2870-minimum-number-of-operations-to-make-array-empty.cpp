class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        
        unordered_map<int, int> map;
        for(int num: nums)
            map[num]++;
        
        int count = 0;
        for(auto it = map.begin(); it != map.end(); it++) {
            if(it->second == 1)
                return -1;
            count += ceil((double)(it->second) / 3);
        }
        
        return count;
    }
};