class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string commStr = "";
        int len = strs.size();
        int n = strs[0].length();
        for(int i=0; i<n; i++) {
            char curr = strs[0][i];
            for(int j=0; j<len; j++) {
                if(strs[j].length() > i && strs[j][i] == curr) {
                    if(j == len-1)
                        commStr += curr;
                } else {
                    return commStr;
                }
            }
        }
        return commStr;
    }
};