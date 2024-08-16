class Solution {
public:
    int maxDistance(vector<vector<int>>& arr) {
        int maxVal = arr[0].back();
        int minVal = arr[0][0];
        int ans = 0;
        
        for(int i=1; i<arr.size(); i++) {
            ans = max(ans, abs(maxVal - arr[i][0]));
            ans = max(ans, abs(arr[i].back() - minVal));
            
            maxVal = max(maxVal, arr[i].back());
            minVal = min(minVal, arr[i][0]);
        }
        
        return ans;
    }
};