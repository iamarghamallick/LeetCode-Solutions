struct TrieNode {
    TrieNode* children[26] = { NULL };
    bool endOfWord = false;
};

class Solution {
public:
    void insertWord(TrieNode* trie, string& product) {
        for(char& c : product) {
            int idx = c - 'a';
            
            if(!trie->children[idx])
                trie->children[idx] = new TrieNode();

            trie = trie->children[idx];
        }
        
        trie->endOfWord = true;
    }

    vector<string> search(TrieNode* trie, string& prefix) {
        vector<string> result;
        
        for(char& c : prefix) {
            int idx = c-'a';
            if(!trie->children[idx])
                return  {};
            
            trie = trie->children[idx];
        }
        
        dfs(trie, prefix, result);
        
        return result;
    }

    void dfs(TrieNode *trie, string pre, vector<string> &result) {
        if (result.size() == 3)
            return;
        
        if (trie->endOfWord)
            result.push_back(pre);
        
        for (int i = 0; i < 26; i++) {
            if (trie->children[i])
                dfs(trie->children[i], pre + (char)(i + 'a'), result);
        }
    }

    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        TrieNode* trie = new TrieNode();
        for(string& prod : products)
            insertWord(trie,prod);

        vector<vector<string>> result;
        string prefix = "";

        for(char& c: searchWord) {
            prefix += c;
            result.push_back(search(trie, prefix)); 
        }

        return result;
    }
};