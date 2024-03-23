class Solution {
public:
    // global variables
    vector<vector<string>> ans;
    vector<string> path;
    
    bool isPalindrom(string &s, int i, int j) {
        while(i < j)
            if(s[i++] != s[j--])
                return false;
        
        return true;
    }
    
    void solve(string &s, int i) {
        if(i == s.size()) {
            ans.push_back(path);
            return;
        }
        
        for(int j=i; j<s.size(); j++) {
            if(isPalindrom(s, i, j)) {
                path.push_back(s.substr(i, j - i + 1));
                solve(s, j+1);
                path.pop_back();
            }
        }
    }
    
    vector<vector<string>> partition(string s) {
        solve(s, 0);
        
        return ans;
    }
};