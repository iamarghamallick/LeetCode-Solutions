class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        vector<string> ans;

        for(int i=0; i<s.size(); i+=k) {
            ans.push_back(s.substr(i, k));
        }

        // process the last string in ans
        while(ans[ans.size() - 1].size() < k) {
            ans[ans.size() - 1] += fill;
        }

        return ans;
    }
};