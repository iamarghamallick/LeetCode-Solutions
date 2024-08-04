class Solution {
public:
    int mod = 1000000007;
    
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        vector<int> arr;
        computeSubarraySums(nums, arr);
        
        sort(arr.begin(), arr.end());
        
        long long ans = 0;
        for(int i=left-1; i<right; i++)
            ans = (ans + arr[i]) % mod;
        
        return ans % mod;
    }
    
private:
    void computeSubarraySums(vector<int> &nums, vector<int> &arr) {
        for(int i=0; i<nums.size(); i++) {
            int curr = 0;
            for(int j=i; j<nums.size(); j++) {
                curr += nums[j];
                arr.push_back(curr);
            }
        }
    }
};