class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        for(int i=1; i<n; i++) {
            int m = triangle[i].size();
            for(int j=0; j<m; j++) {
                if(j == 0) triangle[i][j] += triangle[i-1][j];
                else if(j == m-1) triangle[i][j] += triangle[i-1][j-1];
                else triangle[i][j] += min(triangle[i-1][j-1], triangle[i-1][j]);
            }
        }

        int ans = INT_MAX;
        for(int j=0; j<triangle[n-1].size(); j++) 
            ans = min(ans, triangle[n-1][j]);

        return ans;
    }
};