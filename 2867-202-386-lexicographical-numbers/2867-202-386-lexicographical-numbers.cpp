class Solution {
public:
    void solve(int curr, int n, vector<int> &ans) {
        if(curr > n)
            return;
        
        ans.push_back(curr);
        for(int i=0; i<=9; i++) {
            int next = curr * 10 + i;
            if(next <= n)
                solve(next, n, ans);
            else 
                break;
        }
    }
    
    vector<int> lexicalOrder(int n) {
        vector<int> ans;
        for(int start = 1; start <= 9; start++)
            solve(start, n, ans);
        
        return ans;
    }
};