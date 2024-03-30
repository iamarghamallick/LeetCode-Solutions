class Solution {
public:
    bool isVowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
               c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U';
    }
    
    string reverseVowels(string s) {
        vector<char> v;
        for(int i=0; i<s.size(); i++)
            if(isVowel(s[i]))
                v.push_back(s[i]);
        
        int idx = v.size()-1;
        for(int i=0; i<s.size(); i++)
            if(isVowel(s[i]))
                s[i] = v[idx--];
        
        return s;
    }
};