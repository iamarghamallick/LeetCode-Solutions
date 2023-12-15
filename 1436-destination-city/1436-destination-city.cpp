class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        int n = paths.size();
        unordered_set<string> set;
        
        for(int i=0; i<n; i++)
            set.insert(paths[i][0]);
        
        for(int i=0; i<n; i++) {
            string dest = paths[i][1];
            if(set.find(dest) == set.end())
                return dest;
        }
        
        return "";
    }
};