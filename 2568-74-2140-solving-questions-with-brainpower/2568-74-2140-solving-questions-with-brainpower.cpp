class Solution {
public:
    long long solveUsingMem(vector<vector<int>> &questions, int index, vector<long long> &dp) {
        if (index >= questions.size()) {
            return 0;
        }
        if (dp[index] != -1) {
            return dp[index];
        }

        long long ans = INT_MIN;
        long long include = questions[index][0] + solveUsingMem(questions, index + questions[index][1] + 1, dp);
        long long exclude = solveUsingMem(questions, index + 1, dp);
        ans = max(ans, max(include, exclude));
        dp[index] = ans;
        return ans;
    }

    long long mostPoints(vector<vector<int>>& questions) {
        int index = 0;
        vector<long long> dp(questions.size() + 1, -1);
        return solveUsingMem(questions, index, dp);
    }
};