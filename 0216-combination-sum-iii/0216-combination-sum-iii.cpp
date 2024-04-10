class Solution {
public:
    vector<vector<int>> ans;
    
    void solve(int num, int sum, vector<int>& arr, int k, int n) {
        // Base Case: if we found arr of size k with sum = n
        if(sum == n && k == 0) {
            ans.push_back(arr);
            return;
        }
        
        // if sum exceeds value n, no greater value is possible to take
        if(sum > n)
            return;
        
        // otherwise, check for every other combinations [num, 9]
        for(int i = num; i <= 9; i++) {
            if(i > n)
                return;
            
            arr.push_back(i); // possible value to include
            solve(i + 1, sum + i, arr, k - 1, n); // recursive call
            arr.pop_back(); // while backtracking, erase rejected value
        }
    }
    
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> arr;
        
        solve(1, 0, arr, k, n); // function call
        
        return ans;
    }
};