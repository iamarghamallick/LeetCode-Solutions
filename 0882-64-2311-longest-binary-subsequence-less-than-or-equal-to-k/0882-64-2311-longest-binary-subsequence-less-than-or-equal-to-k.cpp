class Solution {
public:
    int longestSubsequence(string s, int k) {
        int n = s.size();
        int i = n-1;
        long long num = 0;
        while(i >= 0) {
            if(s[i] == '1') {
                if(n-i-1 > 31)
                    break;
                num += (long long)pow(2, n-i-1);
            }
            if(num > k)
                break;
            
            i--;
        }

        int ans = n-i-1;
        for(int j=0; j<i; j++) {
            if(s[j] == '0')
                ans++;
        }

        return ans;
    }
};