class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        int n = garbage.size();
        int m = 0, p = 0, g = 0;
        int lastMindex = 0, lastPindex = 0, lastGindex = 0;
        
        vector<int> distance;
        distance.push_back(0);
        for(int i=0; i<n-1; i++) {
            distance.push_back(distance[i]+travel[i]);
        }
        
        for(int i=0; i<n; i++) {
            string curr = garbage[i];
            bool foundM = false, foundP = false, foundG = false;
            for(int j=0; j<curr.size(); j++) {
                if(curr[j] == 'M') {
                    m++;
                    foundM = true;
                } else if(curr[j] == 'P') {
                    p++;
                    foundP = true;
                } else if(curr[j] == 'G') {
                    g++;
                    foundG = true;
                }
            }
            if(i != 0) {
                if(foundM) {
                    m += distance[i] - distance[lastMindex];
                    lastMindex = i;
                }
                if(foundP) {
                    p += distance[i] - distance[lastPindex];
                    lastPindex = i;
                }
                if(foundG) {
                    g += distance[i] - distance[lastGindex];
                    lastGindex = i;
                }
            }
            
        }
        
        return m + p + g;
    }
};