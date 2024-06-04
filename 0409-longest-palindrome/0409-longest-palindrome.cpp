class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> map;
        for(char ch: s)
            map[ch]++;
        
        int count = 0;
        for(char ch: s) {
            if(map[ch] % 2 == 0) {
                count += map[ch];
                map[ch] = 0;
            } else {
                map[ch]--;
                count += map[ch];
                map[ch] = 1;
            } 
        }
        
        for(char ch: s) {
            if(map[ch] == 1) {
                count++;
                break;
            }
        }
        
        return count;
    }
};