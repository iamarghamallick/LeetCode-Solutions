class KthLargest {
public:
    int k;
    vector<int> arr;
    
    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        for(int num : nums)
            arr.push_back(num);
        
        sort(arr.begin(), arr.end());
    }
    
    int add(int val) {
        int i = getIndex(val);
        arr.insert(arr.begin() + i, val);
        return arr[arr.size() - k];
    }

private:
    int getIndex(int val) {
        int left = 0, right = arr.size() - 1;
        while(left <= right) {
            int mid = (left + right) / 2;
            int midVal = arr[mid];
            if(midVal == val)
                return mid;
            if(midVal > val)
                right = mid - 1;
            else 
                left = mid + 1;
        }
        
        return left;
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */