class RecentCounter {
public:
    vector<int> arr;
    
    RecentCounter() {
        arr = vector<int> {};
    }
    
    int ping(int t) {
        arr.push_back(t);
        
        int start = t - 3000;
        int end = t;
        int count = 0;
        
        for(int i=0; i<arr.size(); i++)
            if(arr[i] >= start && arr[i] <= end)
                count++;
        
        return count;
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */