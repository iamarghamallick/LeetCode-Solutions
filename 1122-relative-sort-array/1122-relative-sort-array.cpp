class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        map<int, int> map;
        for(int num : arr1)
            map[num]++;
        
        vector<int> ans(arr1.size());
        int index = 0;
        for(int i=0; i<arr2.size(); i++) {
            for(int j=0; j<map[arr2[i]]; j++)
                ans[index++] = arr2[i];

            map.erase(arr2[i]);
        }
        
        for(auto it = map.begin(); it != map.end(); it++)
            for(int j=0; j<it->second; j++)
                ans[index++] = it->first;
        
        return ans;
    }
};