class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int time = 0;
        
        for(int i=0; i<points.size()-1; i++) {
            int currX = points[i][0];
            int currY = points[i][1];
            int targetX = points[i+1][0];
            int targetY = points[i+1][1];
            
            time += max(abs(targetX-currX), abs(targetY-currY));
        }
        
        return time;
    }
};