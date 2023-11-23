class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        int n = nums.size();
        int m = l.size();
        vector<bool> ans;
        
        for(int i=0; i<m; i++) {
            vector<int> subarr;
            for(int j=l[i]; j<=r[i]; j++) {
                subarr.push_back(nums[j]);
            }
            sort(subarr.begin(), subarr.end());
            int diff = subarr[1]-subarr[0];
            int j=2;
            for(; j<subarr.size(); j++) {
                if(subarr[j]-subarr[j-1] != diff) {
                    ans.push_back(false);
                    break;
                }
            }
            if(j == subarr.size())
                ans.push_back(true);
        }
        
        return ans;
    }
};