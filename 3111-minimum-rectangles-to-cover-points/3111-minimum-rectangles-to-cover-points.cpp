class Solution {
public:
    static bool comp(vector<int> a, vector<int> b) {
        return a[0] < b[0];
    }
    
    int minRectanglesToCoverPoints(vector<vector<int>>& points, int w) {
        sort(points.begin(), points.end(), comp);
        
        int n = points.size();
        int count = 0;
        int start = 0;
        
        while(start < n) {
            int i = start;
            
            for(; i<n; i++)
                if(points[i][0] > points[start][0] + w)
                    break;
            
            start = i;
            count++;
        }
        
        return count;
    }
};