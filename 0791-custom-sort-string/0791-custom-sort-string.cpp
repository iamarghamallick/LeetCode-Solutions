class Solution {
public:
    string customSortString(string order, string s) {
        unordered_map<char, int> map;
        
        for(char c : s)
            map[c]++;
        
        string ans = "";
        for(char c : order)
            while(map[c]-- > 0)
                ans += c;
        
        for(auto &[c, count] : map)
            while(count-- > 0)
                ans += c;
        
        return ans;
    }
};