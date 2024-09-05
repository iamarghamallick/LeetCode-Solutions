class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int m = rolls.size();
        int total = 0;
        for(int roll : rolls)   total += roll;
        
        //     (total + remaining) / (m + n) = mean
        // =>  remaining = mean * (m + n) - total
        int remaining = (mean * (m + n)) - total;
        
        // now break this remaining into n integer parts
        if(remaining < n || remaining > 6 * n)   return {};
        
        vector<int> ans(n, remaining / n);
        remaining %= n;
        int i = 0;
        while(remaining--)
            ans[i++] += 1;
        
        return ans;
    }
};