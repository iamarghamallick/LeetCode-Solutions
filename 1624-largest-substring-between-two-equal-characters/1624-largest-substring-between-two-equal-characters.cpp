class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        int n = s.size();
        unordered_map<char, int> map;
        int ans = -1;
        
        for(int i=0; i<n; i++)
            if(map.find(s[i]) != map.end())
                ans = max(ans, i - map[s[i]] - 1);
            else
                map[s[i]] = i;
        
        return ans;
    }
};