class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        int count = 0;
        vector<bool> valid(26, false);
        for(int i=0; i<allowed.size(); i++)
            valid[allowed[i] - 'a'] = true;
        
        for(int i=0; i<words.size(); i++) {
            for(int j=0; j<words[i].size(); j++) {
                if(!valid[words[i][j] - 'a'])
                    break;
                if(j == words[i].size() - 1)
                    count++;
            }
        }
        
        return count;
    }
};