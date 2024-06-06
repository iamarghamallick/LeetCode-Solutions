class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();
        
        if(n % groupSize != 0) return false;
        
        map<int, int> map;
        for(int num : hand)
            map[num]++;
        
        while(!map.empty()) {
            int curr = map.begin()->first;
            
            for(int i=0; i<groupSize; i++) {
                if(map[curr + i] == 0)
                    return false;
                
                map[curr + i]--;
                
                if(map[curr + i] < 1)
                    map.erase(curr + i);
            }
        }
        
        return true;
    }
};