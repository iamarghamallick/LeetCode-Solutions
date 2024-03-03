class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> a;
        set<int> s;

        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                s.insert(grid[i][j]);
                a.push_back(grid[i][j]);
            }
        }
        
        int sSum = 0;
        for(auto num: s)
            sSum += num;
        
        int nSum = a.size() * (a.size() + 1) / 2;
        
        int missing = nSum - sSum;
        
        int aSum = 0;
        aSum = accumulate(a.begin(), a.end(), aSum);
        
        int repeat = aSum - sSum;
        
        return vector<int> {repeat, missing};
    }
};