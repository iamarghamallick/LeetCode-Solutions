class ProductOfNumbers {
public:
    vector<int> nums;

    ProductOfNumbers() {
        nums = vector<int> {};
    }
    
    void add(int num) {
        nums.push_back(num);
    }
    
    int getProduct(int k) {
        int prod = 1;
        for(int i = nums.size() - k; i < nums.size(); i++)
            prod *= nums[i];
        return prod;
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */