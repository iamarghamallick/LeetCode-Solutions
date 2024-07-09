class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        int n = customers.size();
        double waitingTime = 0;
        int currTime = customers[0][0]; // initial starting time
        
        for(int i=0; i<n; i++) {
            int arrival = customers[i][0];
            int time = customers[i][1];
            if(currTime < arrival)
                currTime = arrival;
            int finishingTime = currTime + time;
            waitingTime += finishingTime - arrival;
            currTime = finishingTime;
        }
        
        return waitingTime / n;
    }
};