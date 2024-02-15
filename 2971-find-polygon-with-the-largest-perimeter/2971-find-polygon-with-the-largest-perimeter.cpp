class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int n = nums.size();

        long long ans = -1;
        long long pre = nums[0] + nums[1];

        for(int i = 2; i < n; i++){
            if(pre > nums[i]){
                ans = max(ans, pre + nums[i]);
            }

            pre += nums[i];
        }

        return ans;
    }
};