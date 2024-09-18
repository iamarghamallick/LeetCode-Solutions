class Solution {
public:
    string largestNumber(vector<int>& nums) {
        int n = nums.size();
        vector<string> arr;
        for(int num : nums)
            arr.push_back(to_string(num));
        
        sort(arr.begin(), arr.end(), [](const string a, const string b) {
            return a + b > b + a;
        });
        
        if(arr[0] == "0")
            return "0";
        
        string ans = "";
        for(string s : arr)
            ans += s;
        
        return ans;
    }
};