class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans(numRows);
        int coef = 1;
        for(int i=0; i<numRows; i++) {
            vector<int> subans(i+1);
            for(int j=0; j<i; j++) {
                if(i==0 || j==0)
                    coef = 1;
                else 
                    coef = coef * (i-j+1) / j;
                subans[j] = coef;
            }
            subans[i] = 1;
            ans[i] = subans;
        }
        return ans;
    }
};