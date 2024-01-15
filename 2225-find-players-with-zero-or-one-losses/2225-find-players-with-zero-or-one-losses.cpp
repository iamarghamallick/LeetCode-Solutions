class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        vector<int> part(1e5 + 10, 0), lose(1e5 + 10, 0);

        for(auto i : matches){
            part[i[0]] = part[i[1]] = 1;
            ++lose[i[1]];
        }

        vector<vector<int>> ans(2);
        for(int i = 1; i < 1e5 + 10; i++) {
            if(part[i]) {
                if(lose[i] == 1)
                    ans[1].push_back(i);
                else if(lose[i] == 0)
                    ans[0].push_back(i);
            }
        }

        return ans;
    }
};