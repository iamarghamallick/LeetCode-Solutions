class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        vector<pair<int, int>> arr;
        for(vector<int> interval : intervals) {
            arr.push_back({interval[0], 1});
            arr.push_back({interval[1] + 1, -1});
        }
        
        sort(arr.begin(), arr.end());
        
        int ans = 0, curr = 0;
        for(auto event : arr) {
            curr += event.second;
            ans = max(ans, curr);
        }
        
        return ans;
    }
};