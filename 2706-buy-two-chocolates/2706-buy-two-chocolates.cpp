class Solution {
public:
    int buyChoco(vector<int>& p, int m) {
        sort(p.begin(), p.end());
        int ans = m - (p[0]+p[1]);
        return ans < 0 ? m : ans;
    }
};