class Solution {
public:
    int solve(int start, string s, unordered_set<string> &set) {
        if(start == s.size())
            return 0;
        
        int maxCount = 0;
        for(int end = start + 1; end <= s.size(); end++) {
            string subs = s.substr(start, end - start);
            if(set.find(subs) == set.end()) {
                set.insert(subs);
                maxCount = max(maxCount, 1 + solve(end, s, set));
                set.erase(subs);
            }
        }
        
        return maxCount;
    }
    
    int maxUniqueSplit(string s) {
        unordered_set<string> set;
        return solve(0, s, set);
    }
};