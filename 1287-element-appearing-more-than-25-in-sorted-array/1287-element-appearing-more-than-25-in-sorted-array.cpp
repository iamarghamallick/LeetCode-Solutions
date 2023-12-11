class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int, int> map;
        
        for(int i=0; i<n; i++) {
            map[arr[i]]++;
            if(map[arr[i]] > n*25/100)
                return arr[i];
        }
        
        return 0;
    }
};