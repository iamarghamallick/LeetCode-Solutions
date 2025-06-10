class Solution {
public:
    int maxDifference(string s) {
        unordered_map<char, int> map;
        int oddMax = 0, evenMin = 100;

        for(char ch : s) map[ch]++;

        for(auto &[_, val] : map) {
            if(val % 2 == 0) // even
                evenMin = min(evenMin, val);
            else // odd
                oddMax = max(oddMax, val);
        }

        return oddMax - evenMin;
    }
};