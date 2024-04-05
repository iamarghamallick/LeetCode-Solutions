class SmallestInfiniteSet {
public:
    priority_queue<int, vector<int>, greater<int>> pq;
    unordered_set<int> set;
    int i;
    
    SmallestInfiniteSet() {
        i = 1;
        pq.push(i);
    }
    
    int popSmallest() {
        int ans = pq.top();
        if(ans == i) {
            pq.pop();
            pq.push(++i);
        } else {
            pq.pop();
            set.erase(ans);
        }
        
        return ans;
    }
    
    void addBack(int num) {
        if(num < i && set.find(num) == set.end()) {
            set.insert(num);
            pq.push(num);
        }
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */