class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        int n = names.size();
        unordered_map<int, int> map;
        vector<string> ans(n);
        
        for(int i=0; i<n; i++)
            map[heights[i]] = i;
        
        sort(heights.begin(), heights.end());
        
        for(int i=0; i<n; i++)
            ans[n-1-i] = names[map[heights[i]]];
        
        return ans;
    }
};