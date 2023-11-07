class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        int n = dist.size();
        vector<float> arrival;
        
        for(int i=0; i<n; i++)
            arrival.push_back((float)dist[i]/speed[i]);

        sort(arrival.begin(), arrival.end());

        int ans = 0;
        for(int i=0; i<n; i++) {
            if(arrival[i] <= i) break;
            ans++;
        }

        return ans;
    }
};