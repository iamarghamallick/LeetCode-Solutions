class KthLargest {
private:
    int k;
    priority_queue<int, vector<int>, greater<int>> heap;
public:
    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        for(int num: nums) {
            heap.push(num);
            if(heap.size()>k)
                heap.pop();
        }
    }
    
    int add(int val) {
        heap.push(val);
        if(heap.size() > k) 
            heap.pop();
        return heap.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */