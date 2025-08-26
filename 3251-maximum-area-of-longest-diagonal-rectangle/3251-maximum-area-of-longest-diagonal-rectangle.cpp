class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& a) {
        int n = a.size();
        float maxD = INT_MIN;
        int maxArea = INT_MIN;
        
        for(int i=0; i<n; i++) {
            int l = a[i][0];
            int w = a[i][1];
            float d = sqrt(l*l + w*w);
            if(d > maxD) {
                maxD = d;
                maxArea = l*w;
            } else if(d == maxD) {
                maxArea = max(maxArea, l*w);
            }
        }
        
        return maxArea;
    }
};