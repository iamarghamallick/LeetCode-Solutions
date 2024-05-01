class Solution {
public:
    string reversePrefix(string word, char ch) {
        int start = 0;
        int end = 0;
        while(end < word.size() && word[end] != ch)
            end++;
        
        if(end == 0 || end == word.size())
            return word;
        
        while(start < end) {
            char temp = word[start];
            word[start] = word[end];
            word[end] = temp;
            start++;
            end--;
        }
        
        return word;
    }
};