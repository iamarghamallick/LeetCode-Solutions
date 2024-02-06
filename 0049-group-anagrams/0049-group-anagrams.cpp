class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<vector<int>, vector<string>> grp;

        for(int i = 0; i < strs.size(); i++){
            vector<int> f(26, 0);

            for(auto j : strs[i])
                ++f[j - 'a'];

            grp[f].push_back(strs[i]);
        }

        vector<vector<string>> ans;

        for(auto i : grp)
            ans.emplace_back(i.second);

        return ans;
    }
};