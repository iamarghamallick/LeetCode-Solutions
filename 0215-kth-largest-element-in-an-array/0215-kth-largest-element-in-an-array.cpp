class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        // Create a min heap using priority queue
        priority_queue<int, vector<int>, greater<int>> pq;
        
        for(int i=0; i<nums.size(); i++) {
            // Push the current element onto the min heap
            pq.push(nums[i]);
            
            // If the size of the min heap exceeds K,
            // remove the smallest element
            // By this, we are keeping only k largest element in heap
            // with top element being k-th largest
            if(pq.size() > k)
                pq.pop();
        }
        
        return pq.top();
    }
};