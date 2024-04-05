class StockSpanner {
public:
    vector<int> arr;
    
    StockSpanner() {
        arr = vector<int>{};
    }
    
    int next(int price) {
        arr.push_back(price);
        
        int count = 0;
        int n = arr.size();
        for(int i=n-1; i>=0; i--) {
            if(arr[i] <= price)
                count++;
            else
                break;
        }
        
        return count;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */