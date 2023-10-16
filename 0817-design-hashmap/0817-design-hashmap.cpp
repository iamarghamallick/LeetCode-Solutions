class MyHashMap {
private:
    map<int, int> m;
public:
    MyHashMap() {
        map<int,int> m;
    }
    
    void put(int key, int value) {
        m[key] = value;
    }
    
    int get(int key) {
        auto it = m.find(key);
        if(it != m.end()) 
            return it->second;
        return -1;
    }
    
    void remove(int key) {
        m.erase(key);
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */