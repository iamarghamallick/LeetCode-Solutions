class Solution {
public:
    bool check(string s, string t) {
        int n = s.length();
        unordered_map<char, char> map;
        
        for(int i=0; i<n; i++) {
            char key = s[i], val = t[i];
            if(map.contains(key) && map[key] != val)
                return false;
            map[key] = val;
        }
        
        return true;
    }
    
    bool isIsomorphic(string s, string t) {
        return check(s, t) && check(t, s);
    }
};