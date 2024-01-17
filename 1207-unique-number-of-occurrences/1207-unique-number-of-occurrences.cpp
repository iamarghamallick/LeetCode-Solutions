class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> map;
        set<int> s;
        
        for(int i=0; i<arr.size(); i++)
            map[arr[i]]++;
        
        for(auto i=map.begin(); i!=map.end(); i++) 
            s.insert(i->second);
        
        return map.size() == s.size();
    }
};