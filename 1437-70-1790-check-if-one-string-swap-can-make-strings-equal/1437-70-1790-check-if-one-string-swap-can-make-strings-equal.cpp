class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        if(s1 == s2)
            return true;

        int index = 0;
        vector<int> arr;
        while(index < s1.size()) {
            if(s1[index] != s2[index])
                arr.push_back(index);
            index++;
        }

        return arr.size() == 2 && 
                s1[arr[0]] == s2[arr[1]] &&
                s2[arr[0]] == s1[arr[1]];
    }
};