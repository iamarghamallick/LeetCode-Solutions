class Solution {
public:
    int minOperations(vector<string>& logs) {
        int folder = 0;
        for(int i=0; i<logs.size(); i++) {
            if(logs[i] == "./")
                continue;
            else if(logs[i] == "../") {
                if(folder > 0)
                    folder--;
            }
            else 
                folder++;
        }
        
        return folder;
    }
};