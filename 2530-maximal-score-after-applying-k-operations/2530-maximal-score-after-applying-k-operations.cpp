class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        int n = nums.size();
        priority_queue<int> pq;
        for(int num : nums) pq.push(num);
        long long score = 0;
        while(k--) {
            int num = pq.top();
            cout << num << " ";
            pq.pop();
            score += num;
            pq.push(ceil((double)num / 3));
        }
        return score;
    }
};