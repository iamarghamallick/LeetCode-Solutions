class Solution {
public:
    int mod = 1e9 + 7;

    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        vector<int> powers;
        for(int i=0; n; i++) {
            if(n&1) {
                powers.push_back(pow(2, i));
            }
            n >>= 1;
        }

        vector<int> ans;

        for(auto query : queries) {
            long long val = 1;
            for(int i=query[0]; i<=query[1]; i++) {
                val = (val * powers[i]) % mod;
            }
            ans.push_back((int)val);
        }

        return ans;
    }
};