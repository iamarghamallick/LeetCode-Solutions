class Solution {
public:
    string removeKdigits(string num, int k) {
        string ans;
        
        for(int i=0; i<num.size(); i++) {
            // main logic ->
            // If the current digit is less than the last digit in ans
                // Remove that last digit from ans
                // Decrement the value of k
            // Append the current digit in ans
            while(!ans.empty() && k && num[i] < ans.back()) {
                k--;
                ans.pop_back();
            }
            ans.push_back(num[i]);
        }
        
        // if we still have digits to remove
        while(k--)
            ans.pop_back();
        
        // if the ans contains any leading zero(s)
        int n = ans.size();
        int i = 0;
        for( ; i<n && ans[i] == '0'; i++);
        
        return ans.empty() || i == n ? "0" : ans.substr(i);
    }
};