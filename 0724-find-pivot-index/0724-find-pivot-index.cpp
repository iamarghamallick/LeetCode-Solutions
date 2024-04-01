class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        int sum = nums[0];
        vector<int> prefixSum(n);
        
        prefixSum[0] = nums[0];
        for(int i=1; i<n; i++) {
            prefixSum[i] += prefixSum[i-1] + nums[i];
            sum += nums[i];
        }
        
        for(int i=0; i<n; i++) {
            if(i == 0) {
                if(sum - prefixSum[i] == 0)
                    return i;
            } else {
                if(prefixSum[i-1] == sum - prefixSum[i])
                    return i;
            }
        }
        
        return -1;
    }
};