class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        unordered_set<int> set(nums.begin(), nums.end());
        int k = set.size();
        int n = nums.size();
        int count = 0;
        unordered_set<int> tempSet;
        for(int i=0; i<n; i++) {
            for(int j=i; j<n; j++) {
                tempSet.insert(nums[j]);
                if(tempSet.size() == k)
                    count++;
            }
            tempSet.clear();
        }

        return count;
    }
};