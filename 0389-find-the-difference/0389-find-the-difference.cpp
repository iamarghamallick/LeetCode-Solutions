class Solution {
public:
    char findTheDifference(string s, string t) {
        for(int i=0; i<s.size(); i++) 
            t[i+1] += t[i]-s[i]; // passing the difference : (t[i]-s[i]) to t[i+1]
        return t[t.length()-1]; // The difference will be carried over to the last element eventually
    }
};