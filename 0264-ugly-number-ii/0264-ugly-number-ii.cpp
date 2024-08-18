class Solution {
public:
    int nthUglyNumber(int n) {
        set<long> set;
        long curr = 1;
        set.insert(curr);
        
        for(int i=0; i<n; i++) {
            curr = *set.begin();
            set.erase(set.begin());
            set.insert(curr * 2);
            set.insert(curr * 3);
            set.insert(curr * 5);
        }
        
        return curr;
    }
};