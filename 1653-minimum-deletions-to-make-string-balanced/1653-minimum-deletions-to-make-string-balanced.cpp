class Solution {
public:
    int minimumDeletions(string s) {
        int n = s.size();
        int a = 0, b = 0, ans = n;
        vector<int> countA(n, 0), countB(n, 0);
        
        for(int i=0; i<n; i++) {
            countB[i] = b;
            if(s[i] == 'b') b++;
        }
        
        for(int i=n-1; i>=0; i--) {
            countA[i] = a;
            if(s[i] == 'a') a++;
        }
        
        for(int i=0; i<n; i++)
            ans = min(ans, countA[i] + countB[i]);
        
        return ans;
    }
};