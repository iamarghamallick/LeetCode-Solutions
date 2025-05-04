class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        unordered_map<int, int> map;
        for(vector<int> &domino: dominoes) {
            int val = domino[0] < domino[1] ? domino[0] * 10 + domino[1] : domino[1] * 10 + domino[0];
            map[val]++;
        }
        int count = 0;
        for(auto it = map.begin(); it != map.end(); it++) {
            int dominoCount = it->second;
            if(dominoCount >= 2) {
                count += (dominoCount * (dominoCount-1)) / 2;
            }
        }
        return count;
    }
};