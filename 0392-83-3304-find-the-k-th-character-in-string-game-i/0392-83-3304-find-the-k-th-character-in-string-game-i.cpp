class Solution {
public:
    char kthCharacter(int k) {
        string s = "a";
        while(s.size() < k) {
            string temp = "";
            for(int i=0; i<s.size(); i++) {
                temp += char((s[i] - 'a' + 1) + 97);
            }
            s += temp;
        }

        return s[k-1];
    }
};