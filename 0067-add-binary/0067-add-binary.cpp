class Solution {
public:
    string addBinary(string a, string b) {
        string ans = "";
        int i = a.size()-1;
        int j = b.size()-1;
        int temp = 0;
        while(i>=0 || j>=0 || temp==1) {
            temp += i>=0 ? a[i]-'0' : 0;
            temp += j>=0 ? b[j]-'0' : 0;
            ans = char(temp%2 + '0') + ans;
            temp /= 2;
            i--; j--;
        }
        return ans;
    }
};