class Solution {
public:
    static bool compare(vector<int>& a, vector<int>& b) {
        return a[1] < b[1];
    }
    
    int eraseOverlapIntervals(vector<vector<int>>& arr) {
        sort(arr.begin(), arr.end(), compare);
        
        int prevEnd = arr[0][1];
        
        int count = 0;
        
        for(int i=1; i<arr.size(); i++) {
            int currStart = arr[i][0];
            int currEnd = arr[i][1];
            
            if(currStart >= prevEnd) {
                count++;
                prevEnd = currEnd;
            }
        }
        
        return arr.size() - count - 1;
    }
};