class Solution {
public:
    vector<int> findIntersectionValues(vector<int>& nums1, vector<int>& nums2) {
        int count1 = 0, count2 = 0;
        
        for(int i=0; i<nums1.size(); i++) {
            if(find(nums2.begin(), nums2.end(), nums1[i]) != nums2.end())
                count1++;
        }
        
        for(int i=0; i<nums2.size(); i++) {
            if(find(nums1.begin(), nums1.end(), nums2[i]) != nums1.end())
                count2++;
        }
        
        return vector<int> {count1, count2};
    }
};