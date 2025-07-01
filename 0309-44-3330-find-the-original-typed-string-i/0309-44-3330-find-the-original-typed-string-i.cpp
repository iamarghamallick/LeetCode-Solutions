class Solution {
public:
    int possibleStringCount(string word) {
        int ans = 1;
        char currChar = word[0];
        int currLen = 1;
        for(int i=1; i<word.size(); i++) {
            if(word[i] == currChar) {
                currLen++;
            } else {
                ans += currLen - 1;
                currChar = word[i];
                currLen = 1;
            }
        }

        ans += currLen - 1;
        return ans;
    }
};