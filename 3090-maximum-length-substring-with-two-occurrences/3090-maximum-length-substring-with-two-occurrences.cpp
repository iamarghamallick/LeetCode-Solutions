class Solution {
public:
    int maximumLengthSubstring(string s) {
        unordered_map<char, int> map;
        int ans = INT_MIN;
        
        int start = 0;
        for(int end=0; end<s.size(); end++) {
            map[s[end]]++;
            
            while(start <= end && map[s[end]] > 2) {
                map[s[start]]--;
                start++;
            }
            
            ans = max(ans, end - start + 1);
        }
        
        return ans;
    }
};