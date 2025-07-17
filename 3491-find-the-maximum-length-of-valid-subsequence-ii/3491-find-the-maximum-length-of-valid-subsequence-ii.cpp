class Solution {
public:
    int maximumLength(vector<int>& nums, int k) {
        int n = nums.size();
        vector<vector<int>> len(k, vector<int>(k, 0));
        int maxLen = 0;

        for(int i=0; i<n; i++) {
            int curr = nums[i] % k;
            for(int prev=0; prev<k; prev++) {
                len[curr][prev] = len[prev][curr] + 1;
                maxLen = max(maxLen, len[curr][prev]);
            }
        }

        return maxLen;
    }
};