class Solution {
public:
    int minimumPushes(string word) {
        vector<int> freq(26, 0);
        for(char c : word)
            freq[c - 'a']++;
        
        sort(word.begin(), word.end(), [&freq](char a, char b) {
            if(freq[a - 'a'] != freq[b - 'a'])
                return freq[a - 'a'] > freq[b - 'a'];
            return a < b;
        });
        
        // cout << word << endl;
        
        int count = 0;
        int keyIndex = 0;
        unordered_map<int, vector<int> > keyboard;
        unordered_map<char, int> key;
        
        for(char c : word)  key[c] = -1;
        
        for(int i=0; i<word.size(); i++) {
            if(key[word[i]] == -1) {
                key[word[i]] = keyIndex % 8;
                keyIndex++;
                keyboard[key[word[i]]].push_back(word[i]);
            }
            
            int push = 0;
            while(keyboard[key[word[i]]][push] != word[i])
                push++;
            
            count += push + 1;
        }
        
        return count;
    }
};