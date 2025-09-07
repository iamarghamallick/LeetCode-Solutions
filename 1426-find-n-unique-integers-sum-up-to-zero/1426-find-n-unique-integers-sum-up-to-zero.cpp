class Solution {
public:
    vector<int> sumZero(int n) {
        int num = 1;
        vector<int> ans;
        for(int i=0; i<n/2; i++) {
            ans.push_back(-1 * num);
            ans.push_back(num);
            num++;
        }
        if(n%2 !=0) ans.push_back(0);
        return ans;
    }
};