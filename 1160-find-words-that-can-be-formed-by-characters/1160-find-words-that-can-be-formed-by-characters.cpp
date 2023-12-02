class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        unordered_map<char, int> map1;
        for(int i=0; i<chars.size(); i++)
            map1[chars[i]]++;
        
        int ans = 0;
        for(int i=0; i<words.size(); i++) {
            string curr = words[i];
            
            unordered_map<char, int> map2;
            for(int j=0; j<curr.size(); j++)
                map2[curr[j]]++;
            
            bool good = true;
            for(auto& [c, freq] : map2) {
                if(map1[c] < freq) {
                    good = false;
                    break;
                }
            }
            
            if(good)
                ans += curr.size();
        }
        
        return ans;
    }
};