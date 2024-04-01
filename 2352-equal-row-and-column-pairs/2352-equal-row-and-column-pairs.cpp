class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int n = grid.size();
        
        map<vector<int>, int> mp;
        for(int j=0; j<n; j++) {
            vector<int> temp;
            for(int i=0; i<n; i++)
                temp.push_back(grid[i][j]);
            mp[temp]++;
        }
        
        int count = 0;
        for(auto x: grid)
            if(mp[x])
                count += mp[x];

        return count;
    }
};