class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        sort(folder.begin(), folder.end());
        vector<string> ans;
        ans.push_back(folder[0]);
        for(int i=1; i<folder.size(); i++) {
            string lastFolder = ans[ans.size() - 1] + "/";
            if(!folder[i].starts_with(lastFolder))
                ans.push_back(folder[i]);
        }
        return ans;
    }
};