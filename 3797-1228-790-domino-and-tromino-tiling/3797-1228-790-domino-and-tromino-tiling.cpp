class Solution {
public:
    int mod = 1e9+7;
    
    int numTilings(int n) {
        vector<long long> v(n+4);
        
        v[0] = 0;
        v[1] = 1;
        v[2] = 2;
        v[3] = 5;
        
        if(n <= 3)
            return v[n];
        
        for(int i=4; i<=n; i++)
            v[i] = (2 * v[i-1] + v[i-3]) % mod;
        
        return v[n];
    }
};