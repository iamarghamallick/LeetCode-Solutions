class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& q) {
        int n = arr.size();
        vector<int> xors(n+1, 0);
        for(int i=1; i<=n; i++) {
            xors[i] = xors[i-1] ^ arr[i-1];
        }
        
        vector<int> ans;
        for(int i=0; i<q.size(); i++) {
            int start = q[i][0];
            int end = q[i][1];
            ans.push_back(xors[end+1] ^ xors[start]);
        }
        
        return ans;
    }
};