class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> ans;
        
        int i = 0, n = nums.size();
	    while (i < n - 1)
	        // skip equal elements
		    if (nums[i] == nums[i + 1]) i += 2;
		    // generate ans
		    else {
			    ans.push_back(nums[i++]);
			    if (ans.size() == 2)
				    return ans;
		    }
	    // corner case
	    if (ans.size() == 1) 
		    ans.push_back(nums.back());
	    return ans;
    }
};