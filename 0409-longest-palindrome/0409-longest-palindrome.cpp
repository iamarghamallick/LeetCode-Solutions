class Solution {
public:
    int longestPalindrome(string s) {
        unordered_set<char> characterSet;
        int res = 0;

        // Loop over characters in the string
        for (char c : s) {
            // If set contains the character, match found
            if (characterSet.find(c) != characterSet.end()) {
                characterSet.erase(c);
                // add the two occurrences to our palindrome
                res += 2;
            } else {
                // add the character to the set
                characterSet.insert(c);
            }
        }

        // if any character remains, we have at least one unmatched
        // character to make the center of an odd length palindrome.
        if (!characterSet.empty()) {
            res++;
        }

        return res;
    }
};