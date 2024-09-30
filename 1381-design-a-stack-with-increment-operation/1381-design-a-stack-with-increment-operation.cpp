class CustomStack {
public:
    int n;
    vector<int> arr;
    int top;
    
    CustomStack(int maxSize) {
        n = maxSize;
        arr = vector<int>(n, -1);
        top = -1;
    }
    
    void push(int x) {
        if(top < n - 1) {
            top++;
            arr[top] = x;
        }
    }
    
    int pop() {
        int temp = -1;
        if(top >= 0) {
            temp = arr[top];
            arr[top] = -1;
            top--;
        }
        return temp;
    }
    
    void increment(int k, int val) {
        for(int i=0; i<min(k, top + 1); i++)
            arr[i] += val;
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */