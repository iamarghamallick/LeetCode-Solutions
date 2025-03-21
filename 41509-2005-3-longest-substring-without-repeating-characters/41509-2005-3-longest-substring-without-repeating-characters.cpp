class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size(), left = 0, right = 0;
        int maxLen = 0;
        unordered_map<char, int> map;
        for(char ch : s)    map[ch] = -1;
        while(right < n) {
            if(map[s[right]] != -1)
                if(map[s[right]] >= left)
                    left = map[s[right]] + 1;

            maxLen = max(maxLen, right - left + 1);
            map[s[right]] = right;
            right++;
        }

        return maxLen;
    }
};