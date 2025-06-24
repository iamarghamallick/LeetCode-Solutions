class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        int n = nums.size();
        unordered_set<int> set;
        for(int i=0; i<n; i++) {
            if(nums[i] == key) {
                int index = i;
                for(int count=0; count<=k; count++) {
                    if(index >= 0) set.insert(index);
                    if(index + k < n) set.insert(index + k);
                    index--;
                }
            }
        }

        vector<int> ans(set.begin(), set.end());
        sort(ans.begin(), ans.end());

        return ans;
    }
};