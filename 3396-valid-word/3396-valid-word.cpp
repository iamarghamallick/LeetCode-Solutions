class Solution {
public:
    bool isValid(string word) {
        if(word.size() < 3)
            return false;
        
        bool v = false, c = false;
        unordered_set<char> vowels;
        vowels.insert('a'); vowels.insert('A');
        vowels.insert('e'); vowels.insert('E');
        vowels.insert('i'); vowels.insert('I');
        vowels.insert('o'); vowels.insert('O');
        vowels.insert('u'); vowels.insert('U');

        for(int i=0; i<word.size(); i++) {
            if(isdigit(word[i])) continue;
            else if(('a' <= word[i] && word[i] <= 'z') ||
                    ('A' <= word[i] && word[i] <= 'Z')) {
                if(vowels.count(word[i]))
                    v = true;
                else 
                    c = true;
            }
            else return false;
        }

        return v && c;
    }
};