#include <set>
#include <random>

class RandomizedSet {
public:
    std::set<int> s;
    std::random_device rd;
    std::mt19937 gen;
    
    RandomizedSet() : gen(rd()) {}
    
    bool insert(int val) {
        int prevSize = s.size();
        s.insert(val);
        int currSize = s.size();
        
        return prevSize != currSize;
    }
    
    bool remove(int val) {
        int prevSize = s.size();
        s.erase(val);
        int currSize = s.size();
        
        return prevSize != currSize;
    }
    
    int getRandom() {
        if (s.empty())  return 0;  
        
        uniform_int_distribution<int> distribution(0, s.size() - 1);
        auto it = std::next(s.begin(), distribution(gen));
        
        return *it;
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
