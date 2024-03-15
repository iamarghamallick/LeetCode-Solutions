class Solution {
public:
    static bool compare(vector<int> a, vector<int> b) {
        return a[1] > b[1];
    }
    
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(), boxTypes.end(), compare);
        
        int maxUnits = 0;
        
        for(int i=0; i<boxTypes.size(); i++) {
            if(truckSize >= boxTypes[i][0]) {
                truckSize -= boxTypes[i][0];
                maxUnits += boxTypes[i][1] * boxTypes[i][0];
            } else {
                maxUnits += boxTypes[i][1] * truckSize;
                break;
            }
        }
        
        return maxUnits;
    }
};