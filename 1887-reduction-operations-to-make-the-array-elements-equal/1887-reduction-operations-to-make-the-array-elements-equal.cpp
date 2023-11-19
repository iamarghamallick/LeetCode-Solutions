class Solution {
public:
    int reductionOperations(vector<int>& a) {
        sort(a.begin(), a.end());
        int n = a.size();
        int ans = 0;
        for(int i=n-2; i>=0; i--) {
            if(a[i+1] > a[i]) {
                ans = ans + n - i - 1;
            }
        }
        
        return ans;
    }
};