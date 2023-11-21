class Solution {
public:
    const int MOD = 1000000007;
    
    int countNicePairs(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> map;
        int count = 0;
        
        for(int i=0; i<n; i++) {
            nums[i] = nums[i] - rev(nums[i]);
            map[nums[i]]++;
            if(map[nums[i]] == 2)   count = (count+1) % MOD;
            else if(map[nums[i]] > 2)   count = (count+map[nums[i]]-1) % MOD;
        }
        
        return count;
    }
    
    int rev(int n) {
        int res = 0;
        while(n) {
            int rem = n % 10;
            res = (res*10) + rem;
            n /= 10;
        }
        
        return res;
    }
};