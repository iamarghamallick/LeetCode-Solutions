class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        int n = nums.size();
        vector<int> arr;

        for(int i=0; i<n; i++) {
            string curr = nums[i];
            reverse(curr.begin(), curr.end());

            int val = 0;
            for(int j=0; j<curr.size(); j++) {
                if(curr[j] == '1') {
                    val += (1 << j);
                }
            }

            arr.push_back(val);
        }

        sort(arr.begin(), arr.end());

        int ans = 0;
        for(int i=0; i<n; i++) {
            if(arr[i] == ans)   ++ans;
            else    break;
        }

        string res = "";
        while(ans) {
            if(ans & 1)     res += '1';
            else    res += '0';
            ans >>= 1;
        }
        while(res.size() < nums[0].size())  
            res += '0';

        reverse(res.begin(), res.end());

        return res;
    }
};