class Solution {
public:
    int numRabbits(vector<int>& answers) {
        unordered_map<int, int> map;
        int totalRabbits = 0;
        for(int ans: answers) map[ans]++;
        for(auto it = map.begin(); it != map.end(); it++) {
            int groupSize = it->first + 1;
            int numOfGroups = (it->first + it->second) / groupSize;
            totalRabbits += numOfGroups * groupSize;
        }

        return totalRabbits;
    }
};