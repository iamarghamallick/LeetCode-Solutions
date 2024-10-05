class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.size() > s2.size())
            return false;
        
        sort(s1.begin(), s1.end());
        for(int i=0; i<=s2.size() - s1.size(); i++) {
            string str = s2.substr(i, s1.size());
            sort(str.begin(), str.end());
            if(str == s1)
                return true;
        }
        return false;
    }
};