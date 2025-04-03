class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n = nums.size();
        vector<int> preMax(n, nums[0]), sufMax(n, nums[n-1]);
        for(int i=1; i<n; i++) {
            preMax[i] = max(preMax[i-1], nums[i]);
            sufMax[n-1-i] = max(sufMax[n-1-i+1], nums[n-1-i]);
        }
        
        long long ans = LLONG_MIN;
        bool allNeg = true;
        
        for(int j=1; j<n-1; j++) {
            int i = j-1;
            int k = j+1;
            long long res = ((long long)preMax[i] - (long long)nums[j]) * (long long)sufMax[k];
            
            ans = res > ans ? res : ans;
            
            if(ans >= 0) allNeg = false;
        }
        
        return allNeg ? 0 : ans;
    }
};