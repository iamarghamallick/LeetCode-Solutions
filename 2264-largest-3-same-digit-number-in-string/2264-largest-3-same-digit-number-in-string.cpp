class Solution {
public:
    string largestGoodInteger(string num) {

        for(int i=9; i>=0; i--) {
            string s = to_string(i)+to_string(i)+to_string(i);
            if(num.find(s) != string::npos)
                return s;
        }
        
        return "";
    }
};