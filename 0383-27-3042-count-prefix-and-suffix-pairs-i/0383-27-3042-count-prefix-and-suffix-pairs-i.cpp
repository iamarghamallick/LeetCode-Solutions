class Solution {
public:
    bool isPrefixAndSuffix(string a, string b) {
        return (b.substr(0, a.length()) == a) && (b.substr(b.length() - a.length()) == a);
    }
    
    int countPrefixSuffixPairs(vector<string>& words) {
        int count = 0;
        
        for(int i=0; i<words.size(); i++)
            for(int j=i+1; j<words.size(); j++)
                if(isPrefixAndSuffix(words[i], words[j]))
                    count++;
        
        return count;
    }
};