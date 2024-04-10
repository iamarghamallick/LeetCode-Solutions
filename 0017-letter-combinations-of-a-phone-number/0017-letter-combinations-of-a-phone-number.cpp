class Solution {
public:
    vector<string> ans;
    
    unordered_map<char, vector<char>> map;
    
    void solve(string n, string s) {
        if(n == "") {
            ans.push_back(s);
            return;
        }
        
        for(int i=0; i<map[n[0]].size(); i++)
            solve(n.substr(1), s + map[n[0]][i]);
    }
    
    vector<string> letterCombinations(string n) {
        if(n == "")
            return vector<string>{};
        
        map['2'] = vector<char> {'a', 'b', 'c'};
        map['3'] = vector<char> {'d', 'e', 'f'};
        map['4'] = vector<char> {'g', 'h', 'i'};
        map['5'] = vector<char> {'j', 'k', 'l'};
        map['6'] = vector<char> {'m', 'n', 'o'};
        map['7'] = vector<char> {'p', 'q', 'r', 's'};
        map['8'] = vector<char> {'t', 'u', 'v'};
        map['9'] = vector<char> {'w', 'x', 'y', 'z'};
        
        solve(n, "");
        
        return ans;
    }
};