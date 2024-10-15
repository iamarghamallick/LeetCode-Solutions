class Solution {
public:
    long long minimumSteps(string s) {
        long long ans = 0, rightOne = 0;
        for(int i=s.size() - 1; i>=0; i--) {
            if(s[i] == '1') ans += rightOne;
            else rightOne++;
        }
        return ans;
    }
};