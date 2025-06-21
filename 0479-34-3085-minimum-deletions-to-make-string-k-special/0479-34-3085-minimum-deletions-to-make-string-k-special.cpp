class Solution {
public:
    vector<vector<int>> dp;

    int solve(int i, int j, vector<int> &freq, int k) {
        if(i == j || abs(freq[i] - freq[j]) <= k)
            return 0;

        if(dp[i][j] != -1)
            return dp[i][j];

        return dp[i][j] = min(freq[i] + solve(i+1, j, freq, k),
                    (freq[j] - freq[i] - k) + solve(i, j-1, freq, k));
    }

    int minimumDeletions(string word, int k) {
        dp = vector<vector<int>> (26, vector<int> (26, -1));
        vector<int> freq(26, 0);
        for(char c : word) freq[c - 'a']++;
        sort(freq.begin(), freq.end());
        return solve(0, 25, freq, k);
    }
};