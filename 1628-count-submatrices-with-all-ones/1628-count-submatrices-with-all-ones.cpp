class Solution {
public:
    int count(vector<int> v) {
        int ans = 0, ones = 0;
        for(int i=0; i<v.size(); i++) {
            if(v[i] == 0) ones = 0;
            else ones++;
            ans += ones;
        }
        return ans;
    }

    int numSubmat(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        int ans = 0;

        for(int i=0; i<n; i++) {
            vector<int> v(m, 1);
            for(int j=i; j<n; j++) {
                for(int k=0; k<m; k++) {
                    v[k] &= mat[j][k];
                }
                ans += count(v);
            }
        }

        return ans;
    }
};