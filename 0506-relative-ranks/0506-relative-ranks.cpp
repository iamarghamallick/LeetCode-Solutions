class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        int n = score.size();
        vector<string> ans(n);
        vector<pair<int, int>> v;
        
        for(int i=0; i<n; i++)
            v.push_back(make_pair(score[i], i));
        
        sort(v.begin(), v.end());
        
        int rank = 3;
        for(int i=n-1; i>=0; i--) {
            if(i == n-1)         ans[v[i].second] = "Gold Medal";
            else if(i == n-2)    ans[v[i].second] = "Silver Medal";
            else if(i == n-3)    ans[v[i].second] = "Bronze Medal";
            else                 ans[v[i].second] = to_string(++rank);
        }
        
        return ans;
    }
};