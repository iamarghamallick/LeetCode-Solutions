class Solution {
public:
    vector<vector<int>> ans;
    
    void solve(int index, vector<int> &arr, int target, vector<int> &temp) {
        if(target == 0) {
            ans.push_back(temp);
            return;
        }
        
        for(int i=index; i<arr.size() && arr[i] <= target; i++) {
            if(i == index || arr[i] != arr[i-1]) {
                temp.push_back(arr[i]);
                solve(i+1, arr, target - arr[i], temp);
                temp.pop_back();
            }
        }
    }
    
    vector<vector<int>> combinationSum2(vector<int>& arr, int target) {
        sort(arr.begin(), arr.end());
        vector<int> temp;
        solve(0, arr, target, temp);
        return ans;
    }
};