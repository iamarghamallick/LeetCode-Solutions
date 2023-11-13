class Solution {
public:
    bool isVowel(char c) {
        return (c=='a' || c=='e' || c=='i' || c=='o' || c=='u' || c=='A' || c=='E' || c=='I' || c=='O' || c=='U');
    }

    string sortVowels(string s) {
        int n = s.size();
        vector<char> v;

        for(int i=0; i<n; i++) {
            if(isVowel(s[i]))   v.push_back(s[i]);
        }

        sort(v.begin(), v.end());

        int vIndex = 0;
        string t = "";
        for(int i=0; i<n; i++) {
            if(isVowel(s[i]))   t += v[vIndex++];
            else    t += s[i];
        }

        return t;
    }
};