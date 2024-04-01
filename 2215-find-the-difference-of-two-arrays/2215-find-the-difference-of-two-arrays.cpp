class Solution {
public:
    vector<int> solve(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> s1, s2;
        for(int num : nums2)
            s2.insert(num);
        
        for(int num : nums1)
            if(s2.find(num) == s2.end())
                s1.insert(num);
        
        return vector<int> (s1.begin(), s1.end());
    }
    
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        return {solve(nums1, nums2), solve(nums2, nums1)};
    }
};