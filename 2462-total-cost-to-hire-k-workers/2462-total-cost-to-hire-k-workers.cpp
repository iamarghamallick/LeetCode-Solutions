class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        priority_queue<int, vector<int>, greater<int>> leftQ, rightQ;
        
        int low = 0, high = costs.size() - 1;
        for(int i=0; i<candidates; i++)
            leftQ.push(costs[low++]);
        for(int i=0; i<candidates && low<=high; i++)
            rightQ.push(costs[high--]);
        
        long long totalCosts = 0;
        
        while(k--) {
            if(!leftQ.empty() && !rightQ.empty() && leftQ.top() <= rightQ.top()) {
                totalCosts += leftQ.top();
                leftQ.pop();
                if(low <= high)  leftQ.push(costs[low++]);
            }
            else if(!leftQ.empty() && !rightQ.empty()) {
                totalCosts += rightQ.top();
                rightQ.pop();
                if(low <= high)  rightQ.push(costs[high--]);
            }
            else if(!leftQ.empty()) {
                totalCosts += leftQ.top();
                leftQ.pop();
            }
            else {
                totalCosts += rightQ.top();
                rightQ.pop();
            }
        }
        
        return totalCosts;
    }
};