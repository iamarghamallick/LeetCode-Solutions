class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string, string> map;
        for(auto& i : knowledge)
            map[i[0]] = i[1];
        
        string ans = "";
        
        string key = "";
        bool flag = false;
        
        for(int i=0; i<s.size(); i++) {
            if(!flag && s[i] != '(' && s[i] != ')')
                ans += s[i];
            
            else if(!flag && s[i] == '(')
                flag = true;
            
            else if(flag && s[i] != ')')
                key += s[i];
            
            else if(flag && s[i] == ')') {
                // evaluate key
                if(map.find(key) == map.end())
                    ans += "?"; // key not found
                else
                    ans += map[key];
                
                key = "";
                flag = false;
            }
        }
        
        return ans;
    }
};