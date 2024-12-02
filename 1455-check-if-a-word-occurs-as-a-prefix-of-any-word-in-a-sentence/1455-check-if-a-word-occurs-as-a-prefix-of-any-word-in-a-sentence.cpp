class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        int n = sentence.size();
        int i = 0, index = 0;
        while(i < n) {
            string str = "";
            while(i < n && sentence[i] != ' ')
                str += sentence[i++];
            index++;
            i++;
            if(str.substr(0, searchWord.size()) == searchWord)
                return index;
        }
        
        return -1;
    }
};