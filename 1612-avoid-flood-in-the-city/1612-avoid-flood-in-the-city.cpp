class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        int n = rains.size();
        unordered_map<int, int> map;
        set<int> set;
        vector<int> ans(n, 1);

        for(int i=0; i<n; i++) {
            int lake = rains[i];

            if(lake == 0) {
                set.insert(i);
            } else {
                ans[i] = -1;

                if(map.count(lake)) {
                    auto it = set.lower_bound(map[lake]);

                    if(it == set.end()) {
                        return {};
                    }

                    int day = *it;
                    ans[day] = lake;
                    set.erase(it);
                }

                map[lake] = i;
            }
        }

        return ans;
    }
};