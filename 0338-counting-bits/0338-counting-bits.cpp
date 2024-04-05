class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans(n+1);
        
        for(int i=0; i<=n; i++) {
            int count = 0;
            int num = i;
            while(num) {
                count += num & 1;
                num >>= 1;
            }
            ans[i] = count;
        }
        
        return ans;
    }
};