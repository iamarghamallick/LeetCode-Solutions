class Solution {
public:
    int minOperations(string s) {
        int n = s.size();
        int zeroCount = 0, oneCount = 0;
        
        for(int i=0; i<n; i++) {
            if(i%2 == 0) {
                if(s[i] != '0') zeroCount++;
                if(s[i] != '1') oneCount++;
            } else {
                if(s[i] != '1') zeroCount++;
                if(s[i] != '0') oneCount++;
            }
        }
        
        return min(zeroCount, oneCount);
    }
};