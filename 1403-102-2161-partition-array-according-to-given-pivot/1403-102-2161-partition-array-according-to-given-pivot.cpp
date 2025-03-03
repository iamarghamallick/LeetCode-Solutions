class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> smaller, larger, equals, ans;
        for(int num: nums) {
            if(num < pivot) smaller.push_back(num);
            else if(num == pivot)   equals.push_back(num);
            else    larger.push_back(num);
        }
        int i = 0;
        while(i < smaller.size())
            ans.push_back(smaller[i++]);
        i = 0;
        while(i < equals.size())
            ans.push_back(equals[i++]);
        i = 0;
        while(i < larger.size())
            ans.push_back(larger[i++]);
        
        return ans;
    }
};