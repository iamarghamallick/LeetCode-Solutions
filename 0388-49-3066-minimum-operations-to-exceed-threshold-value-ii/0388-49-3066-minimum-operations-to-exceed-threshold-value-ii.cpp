class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int count = 0;
        priority_queue<long long, vector<long long>, greater<long long>> pq;
        for(int num: nums) pq.push(num);
        while(!pq.empty() && pq.top() < k) {
            long long x = pq.top(); pq.pop();
            long long y = pq.top(); pq.pop();
            pq.push(min(x, y) * 2 + max(x, y));
            count++;
        }
        return count;
    }
};