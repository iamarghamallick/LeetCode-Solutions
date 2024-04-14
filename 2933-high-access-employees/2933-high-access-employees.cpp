class Solution {
public:
    static bool comp(vector<string> a, vector<string> b) {
        if(a[0] != b[0])
            return a[0] < b[0];
        
        return a[1] < b[1];
    }
    
    int toInteger(string s) {
        stringstream ss;
        ss << s;
        int val = 0;
        ss >> val;
        return val;
    }
    
    int toMinute(string s) {
        int h = toInteger(s.substr(0, 2));
        int m = toInteger(s.substr(2));
        int ans = h * 60 + m;
        return ans;
    }
    
    int timeDiff(string start, string end) {
        return toMinute(end) - toMinute(start);
    }
    
    vector<string> findHighAccessEmployees(vector<vector<string>>& arr) {
        sort(arr.begin(), arr.end(), comp);
        vector<string> ans;
        
        string curr = "";
        int freq = 0;
        int maxFreq = 0;
        int startIndex = -1;
        
        for(int i=0; i<arr.size(); i++) {
            if(arr[i][0] != curr) {
                if(maxFreq >= 3)    ans.push_back(curr);
                
                curr = arr[i][0];
                startIndex = i;
                freq = 1;
                maxFreq = 1;
            } else {
                if(timeDiff(arr[startIndex][1], arr[i][1]) < 60) {
                    freq++;
                    maxFreq = max(maxFreq, freq);
                } else {
                    while(timeDiff(arr[startIndex][1], arr[i][1]) >= 60) {
                        startIndex++;
                        freq--;
                    }
                    freq++;
                }
            }
        }
        
        if(maxFreq >= 3)    ans.push_back(curr);
        
        return ans;
    }
};