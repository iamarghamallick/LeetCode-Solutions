class Solution {
public:
    bool isPathCrossing(string path) {
        unordered_set<string> visited;
        visited.insert("0,0");
        
        int i = 0, j = 0;
        for(char c: path) {
            if(c == 'N') j++;
            else if(c == 'S') j--;
            else if(c == 'E') i++;
            else if(c == 'W') i--;
            
            string hash = to_string(i) + "," + to_string(j);
            if (visited.find(hash) != visited.end())    return true;
            visited.insert(hash);
        }
        
        return false;
    }
};