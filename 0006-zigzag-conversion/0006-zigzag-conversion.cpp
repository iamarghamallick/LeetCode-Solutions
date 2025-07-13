class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1)
            return s;
            
        int n = s.size();
        vector<string> str(numRows, "");
        int row = 0, next = 1;
        for(int i=0; i<n; i++) {
            str[row] += s[i];

            if(row == 0)
                next = 1;
            else if(row == numRows - 1)
                next = -1;

            row += next;
        }

        string ans = "";
        for(string st : str)
            ans += st;
        
        return ans;
    }
};