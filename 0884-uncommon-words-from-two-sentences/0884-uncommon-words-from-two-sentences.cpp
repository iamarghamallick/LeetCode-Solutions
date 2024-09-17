class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        unordered_map<string, int> map;
        string temp = "";
        for(int i=0; i<s1.size(); i++) {
            if(s1[i] == ' ') {
                map[temp]++;
                temp = "";
            }
            else 
                temp += s1[i];
        }
        map[temp]++;
        temp = "";
        for(int i=0; i<s2.size(); i++) {
            if(s2[i] == ' ') {
                map[temp]++;
                temp = "";
            }
            else 
                temp += s2[i];
        }
        map[temp]++;
        
        vector<string> ans;
        for(auto it = map.begin(); it != map.end(); it++) {
            if(it->second == 1)
                ans.push_back(it->first);
        }
        
        return ans;
    }
};