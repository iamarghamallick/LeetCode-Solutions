class Solution {
public:
    int countHomogenous(string s) {
        int ans = 1;
        int MOD = 1e9+7;
        int streak = 1;

        for(int i=1; i<s.size(); i++) {
            if(s[i] == s[i-1])  streak++;
            else streak = 1;

            ans = (ans+streak) % MOD;
        }

        return ans;
    }
};