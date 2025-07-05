class Solution {
public:
    int findLucky(vector<int>& arr) {
        unordered_map<int, int> map;
        for(int num : arr)  map[num]++;

        int ans = -1;
        for(auto it = map.begin(); it != map.end(); it++) {
            if(it->first == it->second) {
                ans = max(ans, it->first);
            }
        }

        return ans;
    }
};