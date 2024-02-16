class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        map<int, int> f;

        for(auto i : arr)
            ++f[i];

        vector<int> values;
        for(auto i : f)
            values.push_back(i.second);

        sort(values.begin(), values.end());

        int ans = values.size();

        for(auto i : values){
            if(i <= k){
                k -= i;
                --ans;
            }
            else
                break;
        }

        return ans;
    }
};